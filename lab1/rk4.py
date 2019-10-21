import math


def y_def(x=1.0, const=1.0):
    return math.exp(x * const)


def metoda_rk4():
    y = []
    constant = -1.0
    t_min = 0.0
    t_max = 5.0
    time_steps = [0.01, 0.1, 1.0]
    # time_steps = [1.0]
    for step in time_steps:
        f = open("rk4_{}.dat".format(str(step).replace(".", "-")), "w+")
        f_err = open("rk4_{}_err.dat".format(str(step).replace(".", "-")), "w+")

        n = int((t_max - t_min) / step)

        y.insert(0, 1.0)

        for i in range(n + 1):

            k_1 = constant * y[i]
            k_2 = constant * (y[i] + (step/2.0) * k_1)
            k_3 = constant * (y[i] + (step/2.0) * k_2)
            k_4 = constant * (y[i] + step * k_3)

            result = y[i] + (step / 6.0) * (k_1 + 2.0 * k_2 + 2.0 * k_3 + k_4)

            y.insert(i + 1, result)
            argument = i * step
            f.write("{:4.4}\t{:.8}\n".format(float(argument), y[i]))
            f_err.write("{:4.4}\t{:.8}\n".format(float(argument), y[i] - y_def(argument, constant)))

        f.close()
        f_err.close()

    f = open("rk4_definition.dat", "w+")
    step = 0.01
    n = int((t_max - t_min) / step)
    for i in range(n + 1):
        argument = step * float(i)
        result = y_def(argument, constant)
        f.write("{:4.4}\t{:.8}\n".format(argument, result))


if __name__ == "__main__":
    metoda_rk4()  # metoda + blad
