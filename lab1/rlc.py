import math


def voltage(t, omega):
    return 10 * math.sin(t * omega)


def rlc():

    # constants:
    time_step = 1e-4
    R = 100
    L = 0.1
    C = 0.001
    omega_0 = 1 / math.sqrt(L * C)
    T_0 = 2 * math.pi / omega_0
    t_min = 0
    t_max = 4 * T_0

    source_omegas = [0.5 * omega_0, 0.8 * omega_0, 1.0 * omega_0, 1.2 * omega_0]

    for omega in source_omegas:
        f = open("rlc_{}.dat".format(str(omega).replace(".", "-")), "w+")

        n = int((t_max - t_min) / time_step)

        # initial values:
        I_arr = []
        Q_arr = []
        I_arr.insert(0, 0.0)
        Q_arr.insert(0, 0.0)

        for i in range(n + 1):

            time = i * time_step
            time_next_half = (i + 0.5) * time_step
            time_next = (i + 1.0) * time_step

            V = voltage(time, omega)
            V_next_half = voltage(time_next_half, omega)
            V_next = voltage(time_next, omega)

            Q = Q_arr[i]
            I = I_arr[i]

            k_1_q = I
            k_1_i = V/L - 1/(L*C) * Q - R/L * I

            k_2_q = I + time_step/2. * k_1_i
            k_2_i = V_next_half/L - 1/(L*C) * (Q + time_step/2 * k_1_q) - R/L * (I + time_step/2 * k_1_i)

            k_3_q = I + time_step/2 * k_2_i
            k_3_i = V_next_half/L - 1/(L*C) * (Q + time_step/2 * k_2_q) - R/L * (I + time_step/2 * k_2_i)

            k_4_q = I + time_step * k_3_i
            k_4_i = V_next / L - 1 / (L * C) * (Q + time_step / 2 * k_3_q) - R / L * (I + time_step * k_3_i)

            Q_arr.append(Q + time_step/6 * (k_1_q + k_2_q + k_3_q + k_4_q))
            I_arr.append(I + time_step/6 * (k_1_i + k_2_i + k_3_i + k_4_i))

            f.write("{:4.4}\t{:.8}\t{:.8}\n".format(float(time), Q, I))

        f.close()


if __name__ == "__main__":
    rlc()  # metoda + blad
