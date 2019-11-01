
def rk2(x, v, d_t, alpha):
    
    k_1_x = v
    k_1_v = alpha*(1 - x*x) * v - x

    k_2_x = v + d_t * k_1_v
    k_2_v = alpha*(1 - (x + d_t*k_1_x)**2)*(v + d_t * k_1_v) - (x + d_t*k_1_x)

    x_new = x + d_t/2 * (k_1_x + k_2_x)
    y_new = v + d_t/2 * (k_1_v + k_2_v)

    return (x_new, y_new)