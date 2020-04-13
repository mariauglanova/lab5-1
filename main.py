import numpy as np
from math import factorial
from scipy.integrate import quad


def get_series(x, eps = 5e-5):
    r = 1
    n = 1
    t = 1
    while abs(t) >= eps:
        t = (-1)**n * x**(2*n)/factorial(n)
        r += t
        n += 1
    return r

def rect(x, f):
    return h*sum([f(i) for i in x[:len(x)-1]])


h = 5e-5;
x = np.arange(0, 1+h, h)
print(rect(x, get_series), abs(quad(lambda x: np.exp(-x**2), 0, 1)[0] - rect(x, get_series)))