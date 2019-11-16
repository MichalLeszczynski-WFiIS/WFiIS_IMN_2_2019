# WFiIS_IMN_2_2019
Code written for subject "Inżynierskie metody nuemryczne" on AGH UST

## Running the code:
There are some projects written in C++ or Python3

## Running python code:

To run the code you need to have installed python3 and gnuplot and run commands:
```
make init # in case of packages specified in requirements.txt
make
```

### Available make commands (need to be in the lab* dir)

Command         | Description
-----           | -----------
`make init`     | Downloads all necessary python packages.
`make`          | Clean, run and draw.
`make run`      | Generates *.dat files with the script output.
`make draw`     | Generates plots from *.dat files.
`make clean`    | Deletes *.dat and *.jpeg files.

## Running c++ code:

To run the code you need to have installed g++ and gnuplot and run commands:
```
make
```

### Available make commands (need to be in the lab* dir)

Command         | Description
-----           | -----------
`make`          | Compile, run and draw plots.
`make run`      | Runs program without any cleaning.
`make gendata`  | Generates *.dat files (make run + clean compiled files).
`make draw`     | Generates plots from *.dat files.
`make clean`    | Deletes data files and compilation outputs.
`make memcheck` | Runs program with a Valgrind.
