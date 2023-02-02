# Binome
- **Ilyas RACHEDI**
- **Nadine SAADI**

## Les tests utilisés pour valider le do [do]

```
./do -a true  false|| echo "false"
./do -a false true || echo "false"
./do -a false false|| echo "false"
./do -a true true|| echo "false"

./do -o true  false|| echo "false"
./do -o false true || echo "false"
./do -o false false|| echo "false"
./do -o true true|| echo "false"

./do -a -c  code  true false|| echo "false"
./do -a -c  false true code || echo "false"
./do -a -c  true false code || echo "false"

./do -o -c  code  true false|| echo "false"
./do -o -c  false true code || echo "false"
./do -o -c  true false code || echo "false"

./do -a -c  true code true && echo "true"
./do -a -c  true true code && echo "true"
./do -a -c  code true true && echo "true"

./do -o -c  true code true && echo "true"
./do -o -c  true true code && echo "true"
./do -o -c  code true true && echo "true"

./do -a -c -k code  true false|| echo "false"
./do -a -c -k false true code || echo "false"
./do -a -c -k true false code || echo "false"

./do -a -c -k true code true && echo "true"
./do -a -c -k true true code && echo "true"
./do -a -c -k code true true && echo "true"

./do -o -c -k code  true false && echo "true"
./do -o -c -k false true code && echo "true"
./do -o -c -k true false code && echo "true"

```



