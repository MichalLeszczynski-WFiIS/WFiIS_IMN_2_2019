import math


def y_def(x=1.0, const=1.0):
    return math.exp(x * const)


def metoda_rk2():
    y = []
    constant = -1.0
    t_min = 0.0
    t_max = 5.0
    time_steps = [0.01, 0.1, 1.0]
    # time_steps = [1.0]
    for step in time_steps:
        f = open("rk2_{}.dat".format(str(step).replace(".", "-")), "w+")
        f_err = open("rk2_{}_err.dat".format(str(step).replace(".", "-")), "w+")

        n = int((t_max - t_min) / step)

        y.insert(0, 1.0)

        for i in range(n + 1):

            k_1 = constant * y[i]
            k_2 = constant * (y[i] + step * k_1)

            argument = i * step
            result = y[i] + (step / 2.0) * (k_1 + k_2)
            y.insert(i + 1, result)
            f.write("{:4.4}\t{:.8}\n".format(float(argument), y[i]))
            f_err.write("{:4.4}\t{:.8}\n".format(float(argument), y[i] - y_def(argument, constant)))

        f.close()
        f_err.close()

    f = open("rk2_definition.dat", "w+")
    step = 0.01
    n = int((t_max - t_min) / step)
    for i in range(n + 1):
        argument = step * float(i)
        result = y_def(argument, constant)
        f.write("{:4.4}\t{:.8}\n".format(argument, result))


if __name__ == "__main__":
    metoda_rk2()  # metoda + blad
