from rk2 import rk2
from trapez import trapez
from time_step_control import time_step_control

if __name__ == "__main__":

    x_0 = 0.01
    v_0 = 0
    d_t_0 = 1
    S = 0.75
    p = 2
    t_max = 40
    alpha = 5
    TOLS = [1e-2, 1e-5]


    for TOL in TOLS:

        time_step_control(d_t_0, x_0, v_0, t_max, alpha, rk2, p, TOL, S)
        time_step_control(d_t_0, x_0, v_0, t_max, alpha, trapez, p, TOL, S)