# WFiIS_IMN_2_2019
Code written for subject "Inżynierskie metody nuemryczne" on AGH UST

## Running the code:
To run the code you need to have installed python3, gnuplot and run commands:
```
make init # in case of packages specified in requirements.txt
make
```

## Available make commands (need to be in the lab* dir)

Command         | Description
-----           | -----------
`make`          | Clean, run and draw.
`make run`      | Generates *.dat files with the script output.
`make draw`     | Generates plots from *.dat files.
`make clean`    | Deletes *.dat and *.jpeg files.
`make init`     | Downloads all necessary python packages.
