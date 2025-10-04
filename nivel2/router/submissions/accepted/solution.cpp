#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>
#include <cfloat>
using namespace std;

bool esta_contenido(pair<double,double> p, pair<double, double> c, double r) {
    if (r < 0) {
        return false;
    }
	// distancia al cuadrado entre (x,y) y (c_x,c_y)
	double dx = p.first-c.first;
	double dy = p.second-c.second;
	double dist = dx*dx + dy*dy;
	return dist <= r*r + 1e-9;
}

void circ2puntos(pair<double,double> p1, pair<double,double> p2, pair<double,double>& c, double& r) {
	double dx = p1.first-p2.first;
	double dy = p1.second-p2.second;
	double dist = sqrt(dx*dx + dy*dy);
	r = dist/2.f;
	c.first = (p1.first+p2.first)/2.f;
	c.second= (p1.second+p2.second)/2.f;
}

void circ3puntos(pair<double,double> p1, pair<double,double> p2, pair<double,double> p3, pair<double,double>& c, double& r) {
	// https://en.wikipedia.org/wiki/Circumcircle#Cartesian_coordinates_2
	// https://blog.vivaxsolutions.com/2022/03/constructions-and-loci-for-gcse-and.html
	pair<double, double> B({p2.first-p1.first, p2.second-p1.second});	// p2-p1
	pair<double, double> C({p3.first-p1.first, p3.second-p1.second});	// p3-p1
	double D = 2*(B.first*C.second - B.second*C.first);
	// esta condicion es jodida (puntos colineares)
	if (fabs(D) < 1e-9) {
		c = {0,0};
		r = FLT_MAX;
		return;
	}
	c.first = (C.second*(B.first*B.first + B.second*B.second) - B.second*(C.first*C.first + C.second*C.second))/D;
	c.second = (B.first*(C.first*C.first + C.second*C.second) - C.first*(B.first*B.first + B.second*B.second))/D;
	c.first = c.first + p1.first;
	c.second = c.second + p1.second;
	double dx = c.first - p1.first;
	double dy = c.second - p1.second;
	r = sqrt(dx*dx + dy*dy);
}

void reconstruir(list<pair<double,double>> P, pair<double,double> R, pair<double,double>& C, double& r, list<pair<double,double>>& CP) {
	// caso trivial de solo dos puntos
	if (P.size() == 1) {
		circ2puntos(*P.begin(),R,C,r);
		CP = list<pair<double,double>>({*P.begin(),R});
		return;
	}

    r = FLT_MAX;
	pair<double,double> c_aux;
	double r_aux;
	list<pair<double,double>> cp_aux;
	// evaluar circulos que se forman entre R y los puntos CP
	// 2 puntos
	for (list<pair<double,double>>::iterator it=P.begin(); it!=P.end(); ++it) {
		circ2puntos(R,*it,c_aux,r_aux);
		// verificar que contenga todos los puntos
		list<pair<double,double>>::iterator it1 = P.begin();
		while(it1 != P.end() && esta_contenido(*it1, c_aux, r_aux))
			++it1;

		if (r_aux < r && it1 == P.end()) {
			cp_aux = {R, *it};
			C = c_aux;
			r = r_aux;
		}
	}

	// 3 puntos
	for (list<pair<double,double>>::iterator it1=P.begin(); it1!=prev(P.end()); ++it1) {
		for (list<pair<double,double>>::iterator it2=next(it1); it2!=P.end(); ++it2) {
			circ3puntos(R, *it1, *it2, c_aux, r_aux);
			// verificar que contenga todos los puntos
			list<pair<double,double>>::iterator it3 = P.begin();
			while(it3 != P.end() && esta_contenido(*it3, c_aux, r_aux))
				++it3;

			if (r_aux < r && it3 == P.end()) {
				cp_aux = list<pair<double,double>>({R, *it1, *it2});
				C = c_aux;
				r = r_aux;
			}
		}
	}

	CP = cp_aux;
}

int main(int argc, char *argv[]) {
	// numero de puntos
	int N;
	cin >> N;

	// caso trivial
	if (N == 0) {
		cout << 0.00 << ' ' << 0.00 << ' ' << 0.00 << endl;
		return 0;
	}

	// conjunto de puntos
	list<pair<double,double>> P;
	// circulo (centro, radio y puntos que lo componen)
	pair<double,double> C;
	double r = 0;
	list<pair<double,double>> CP;

	// el primer punto define el primer circulo de radio 0
	cin >> C.first >> C.second;
	P.push_back(C);
	CP.push_back(C);

	// reservamos memoria para R
	pair<double,double> R;
	for (int i=1; i<N; ++i) {
		// punto nuevo
		cin >> R.first >> R.second;

		// si el R no esta contenido en el circulo, reconstruir el circulo
		if (!esta_contenido(R,C,r)) {
			reconstruir(P,R,C,r,CP);
		}

		P.push_back(R);
	}

	cout << setprecision(2) << fixed << C.first << ' ' << C.second << ' ' << r << endl;

	return 0;
}
