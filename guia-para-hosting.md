# Judgehosts

Para ejecutar los judgehosts, ejecutar

```sh
/opt/domjudge/judgehost/bin/judgedaemon -n 2
```

cambiar el `2` por el juez que necesites.

Si ocurre un error con `libcgroupd`, ejecutar
```sh
echo +cpuset | sudo tee -a /sys/fs/cgroup/cgroup.subtree_control
```

## Reiniciar judgedaemon

Si se cerro fiero y no deja arrancar otra vez, buscar el id con
```sh
ps -ef
```

buscar el PID con ctrl+F ("judgedaemon") y matarlo con
```sh
kill -9 [PID]
```

# Agregar matrix

Para gregar la clase `matrix` al entorno de c++, copiar el archivo `zinjai-add-fupro-20170608/complements/FuPro/include/matrix` en `/chroot/domjudge/usr/include/` y reiniciar los judgedaemons

# Hora

El server esta en UTC, por lo que hay que hay que sumarle 3 horas a la hora deseada.
Por ejemplo, si queres que se active la competencia en

2025-10-03 18:00:00 UTC-3

tenes que poner

2025-10-03 21:00:00 UTC-3

# Configuracion del servidor

Aca usamos `192.168.0.80` pero es la ip que aparece reservada para esta PC en la config del router

En el menu del router chusmear el dhcp server:
- IP Address Pool: 192.168.0.2 - 192.168.0.253
- Address Lease Time: 120
- Default Gateway: 192.168.0.1
- Primary DNS: 192.168.0.80 (El Reserved IP Address que aparece abajo para esta PC)
- Secondary DNS: nada

Chusmear config de `dnsmasq` en `/etc/dnsmasq.conf`:

```
address=/lpc.local/192.168.0.80
listen-address=127.0.0.1,192.168.0.80
bind-interfaces
```

Reiniciar `dnsmasq`
```sh
sudo systemctl status dnsmasq.service
```
