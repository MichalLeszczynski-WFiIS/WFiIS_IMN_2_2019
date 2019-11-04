
def time_step_control(d_t_0, x_0, v_0, t_max, alpha, numeric, p ,TOL, S):
    t = 0
    d_t = d_t_0
    x_n = x_0
    v_n = v_0

    f = open("{}-{}.dat".format(numeric.__name__, TOL), "w+")
    while t < t_max:
        # Two steps
        x_n_1_2, v_n_1_2 = numeric(x_n, v_n, d_t, alpha)
        x_n_2_2, v_n_2_2 = numeric(x_n_1_2, v_n_1_2, d_t, alpha)

        # One step
        x_n_2_1, v_n_2_1 = numeric(x_n, v_n, 2*d_t, alpha)

        # Diff
        E_x = (x_n_2_2 - x_n_2_1) / (2**p - 1)
        E_v = (v_n_2_2 - v_n_2_1) / (2**p - 1)

        max_E = max(abs(E_x), abs(E_v))
        # If acceptable 
        if max_E < TOL :
            t = t + 2 * d_t
            x_n = x_n_2_2
            v_n = v_n_2_2
            f.write("{}\t{}\t{}\t{}\n".format(t, d_t, x_n, v_n))

        # Step update
        d_t = ((S*TOL/max_E)**(1/(p+1))) * d_t
    f.close()

