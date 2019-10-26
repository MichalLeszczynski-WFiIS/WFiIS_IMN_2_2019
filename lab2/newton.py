import math
import numpy as np


def newton():
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

    def last_nonzero(array):
        return array[np.max(np.nonzero(array))]

    def fun(result):
        return alpha * result - beta * (result ** 2)

    # u[n'th element][Iteration number]

    n = int((t_max - t_0) / delta_t)

    u = np.zeros((n + 1, max_mi + 1))

    u[0][0] = u_0

    f = open("newton.dat", "w+")

    for i in range(n):

        mi = 0
        u[i + 1][0] = u[i][0]
        prev_result = last_nonzero(u[i])

        for mi in range(max_mi):

            prev_iter_result = u[i + 1][mi]
            u[i + 1][mi + 1] = prev_iter_result - (
                prev_iter_result
                - prev_result
                - delta_t / 2 * (fun(prev_result) + fun(prev_iter_result))
            ) / (1 - delta_t / 2 * (alpha - 2 * beta * prev_result))

            if u[i + 1][mi + 1] - u[i + 1][mi] < TOL:
                break
        time = i * delta_t
        f.write("{:4.4}\t{:.8}\t{:.8}\n".format(time, prev_result, N - prev_result))

    f.close()


if __name__ == "__main__":
    newton()
