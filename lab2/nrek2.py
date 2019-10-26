import math
import numpy as np


def nrk2():
    beta = 0.001
    N = 500
    gamma = 0.1
    t_0 = 0
    t_max = 100
    delta_t = 0.1
    u_0 = 1
    TOL = 10e-6
    max_mi = 20
    alpha = beta * N - gamma


    u_inf = N - gamma / beta
    v = u_inf / u_0 - 1

    a = np.zeros((3,3))
    a[1][1] = 0.25
    a[1][2] = 0.25 - math.sqrt(3)/6.
    a[2][1] = 0.25 + math.sqrt(3)/6.
    a[2][2] = 0.25

    c = np.zeros(3)
    c[1] = 0.5 - math.sqrt(3)/6.
    c[2] = 0.5 + math.sqrt(3)/6.


    b = np.zeros(3)
    b[1] = 0.5
    b[2] = 0.5

    def last_nonzero(array):
        return array[np.max(np.nonzero(array))]

    def fun(result):
        return alpha * result - beta * (result ** 2)

    def F_1_calc(U_1, U_2, u_n):
        return U_1 - u_n - delta_t * (a[1][1] * fun(U_1) + a[1][2] * fun(U_2))

    def F_2_calc(U_1, U_2, u_n):
        return U_2 - u_n - delta_t * (a[2][1] * fun(U_1) + a[2][2] * fun(U_2))

    def m_calc(i, j, U):
        result = -delta_t * a[i][j] * (alpha - 2*beta*U)
        if i == j:
            result += 1
        return result

    n = int((t_max - t_0) / delta_t)

    u = np.zeros(n + 1)

    u[0] = u_0

    U_1_arr = np.zeros(n)
    U_2_arr = np.zeros(n)

    f = open("nrk2.dat", "w+")

    for i in range(n):

        U_1 = np.zeros(max_mi + 1)
        U_2 = np.zeros(max_mi + 1)

        U_1[0] = u[i]
        U_2[0] = u[i]

        for mi in range(max_mi):

            m = np.zeros((3, 3))
            m[1][1] = m_calc(1, 1, U_1[mi])
            m[1][2] = m_calc(1, 2, U_2[mi])
            m[2][1] = m_calc(2, 1, U_1[mi])
            m[2][2] = m_calc(2, 2, U_2[mi])

            F_1 = F_1_calc(U_1[mi], U_2[mi], u[i])
            F_2 = F_2_calc(U_1[mi], U_2[mi], u[i])
            div = (m[1][1] * m[2][2] - m[1][2] * m[2][1])
            del_U_1 = (F_2 * m[1][2] - F_1 * m[2][2]) / div
            del_U_2 = (F_1 * m[2][1] - F_2 * m[1][1]) / div

            U_1[mi+1] = U_1[mi] + del_U_1
            U_2[mi+1] = U_2[mi] + del_U_2

            if U_1[mi+1] < TOL and U_2[mi+1] < TOL:
                break

        U_1_arr[i] = last_nonzero(U_1)
        U_2_arr[i] = last_nonzero(U_2)

        u[i+1] = u[i] + delta_t * (b[1]*fun(U_1_arr[i + int(c[1]*delta_t)]) + b[2]*fun(U_2_arr[i + int(c[2]*delta_t)]))

        time = i * delta_t
        f.write("{:4.4}\t{:.8}\t{:.8}\n".format(time, u[i], N - u[i]))

    f.close()


if __name__ == "__main__":
    nrk2()
