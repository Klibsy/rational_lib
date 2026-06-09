import ctypes
import os

os.chdir("/home/" + os.getenv("USER") + "/rational_lib")
lib = ctypes.CDLL("./librational.so")

class Rational(ctypes.Structure):
    _fields_ = [("num", ctypes.c_long), ("den", ctypes.c_long)]

lib.rational_create.argtypes = [ctypes.c_long, ctypes.c_long, ctypes.POINTER(Rational)]
lib.rational_create.restype = ctypes.c_int
lib.rational_add.argtypes = [ctypes.POINTER(Rational), ctypes.POINTER(Rational), ctypes.POINTER(Rational)]
lib.rational_add.restype = ctypes.c_int

a = Rational()
b = Rational()
res = Rational()

lib.rational_create(1, 2, ctypes.byref(a))
lib.rational_create(1, 3, ctypes.byref(b))
lib.rational_add(ctypes.byref(a), ctypes.byref(b), ctypes.byref(res))

print(f"Python: 1/2 + 1/3 = {res.num}/{res.den}")
