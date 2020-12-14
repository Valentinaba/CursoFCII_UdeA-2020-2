#!/usr/bin/env python
import os
import sys

os.system( 'g++ Cuenta.cpp CuentaAhorros.cpp CuentaCheques.cpp Main.cpp -o a.out')
os.system( './a.out')