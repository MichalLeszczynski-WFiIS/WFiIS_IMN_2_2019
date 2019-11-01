
def f(v): return v

def g(x, v, alpha): return alpha*(1-x**2)*v - x

def trapez(x, v, d_t, alpha):

    delta = 1e-10

    x_n_1 = x
    v_n_1 = v

    while True:
        
        F = x_n_1 - x - d_t/2 * (f(v) + f(v_n_1))
        G = v_n_1 - v - d_t/2 * (g(x, v, alpha) + g(x_n_1, v_n_1, alpha))

        a_1_1 = 1
        a_1_2 = -d_t/2
        a_2_1 = -d_t/2 * (-2*alpha*x_n_1*v_n_1 -1)
        a_2_2 = 1 - d_t/2 * alpha * (1 - (x_n_1)**2)

        div = (a_1_1*a_2_2 - a_1_2*a_2_1)
        dx = (-F*a_2_2 - (-G) * a_1_2) / div
        dv = (a_1_1 *(-G) - a_2_1 * (-F)) / div

        x_n_1 += dx
        v_n_1 += dv

        if dx < delta and dv < delta:
            break

    return (x_n_1, v_n_1)