# topology

This is a topology analysis package[Original Author: Xing-Yu Zhou]

## Pre requirement

> Use lxslc7 to login LS5

> Set up BOSS-X.X.X environment to use ROOT

## Install v1.9.5

> mkdir -p $YOURPATH

> cd $YOURPATH

> git clone https://github.com/zhixing1996/topology.git v1.9.5

## Compile source code

> ./compile.sh

## Set up environment variable

> NOTE: ***The environment variable is aimed at bash shell mode, if your shell mode is tcshell, use [XXXX XX]bash command to change to bash shell mode, when all the things have been done, use XXXX:XX$exit to come back to tcshell.***

> source setup.sh, after the first compilation, use bahs to change shell mode and then source setup.sh, if you want to apply topology analysis.

## Execute

> After setup your own environment variable, you can apply topology analysi in anywhere you want, use this command: topoana.exe [your-topoana,card]

## Explanations about parameters in share/topoana.card

> Names of input root files: your root file about to be analyzed

> Tree name: tree name conatining MCTruth information

> Storage type of the raw input topology data (Four options: AI, VI, MIV, and MDV. Default: AI): XXXXXXXXXXXXXXXXXXXXXXXXXXXXX

> Method to apply cut to array variables: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

> Maximum hierarchy of heading decay branches to be processed in each event: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

> Ignore the decay of the following particles: e.g., e+e- --> D+D-pi+pi-, D- in this part means you do not care about decay method of D-, other particles can be found in share/pid_3pchrg_txtpnm_texpnm_iccp.dat

> Ignore the decay of the daughters of the following particles: e.g., e+e- --> D+D-pi+pi-, D+ in thie part means that you only care about only the first level of decay, e.g. D+ --> K-pi+pi+

> Component analysis --- decay trees: Y stands for iluminations for initial and final states with all resonances, N stands for iluminations only for inital and final states without resonances

> Component analysis --- decay initial-final states: XXXXXXXXXXXXXXXXXXXXXXXXXX

> Component analysis --- decay branches of particles: XXXXXXXXXXXXXXXXXXXXXXXXX

> Component analysis --- production branches of particles: XXXXXXXXXXXXXXXXXXXXXXXX

> Component analysis --- inclusive decay branches: define the inclusive channel you want to display, shown in all info part, examples can be seen in examples/example-2.card, example-3.card, exampl-6.card

> Component analysis --- intermediate-resonance-allowed decay branches: XXXXXXXXXXXXXXXXXXXXXXX

> Signal identification --- decay trees: your signal channel, but are the explicit channel you want to show in the signal info part, examples can be seen in example-4

> Signal identification --- decay initial-final states: XXXXXXXXXXXXXXXXXXXXXXX

> Signal identification --- particles: XXXXXXXXXXXXXXXXXXXX

> Signal identification --- decay branches: XXXXXXXXXXXXXXXXXXXXX

> Signal identification --- inclusive decay branches: XXXXXXXXXXXXexample-5.card

> Signal identification --- cascade decay branches: your signal channel, examples can be seen in examples/exampl-1.card, shown in the signal info part

> Signal identification --- inclusive cascade decay branches: XXXXXXXXXXXXXXXXXXXXXXX

> Signal identification --- intermediate-resonance-allowed decay branches: XXXXXXXXXXXXXXXXXXX

> Signal identification --- inclusive or intermediate-resonance-allowed cascade decay branches: XXXXXXXXXXXXXXXXXXX

> Analysis tasks for signal identifications (Three options: TC, T and C. Default: TC): TC, XXXXXXXXX, T, XXXXXXXX, C, XXXXXXX

> Use array branches to store topology tags in the output root files when possible (Two options: Y and N. Default: N): XXXXXXXXXXXXXXXXXX

## For developers

- Fork the code with your personal github ID. See [details](https://help.github.com/articles/fork-a-repo/)

> git clone https://github.com/zhixing1996/topology.git

- Make your change, commit and push

> git commit -a -m "Added feature A, B, C"

> git push

- Make a pull request. See [details](https://help.github.com/articles/using-pull-requests/)

## Some styles to follow

- Minimize the number of main c++ files

- Keep functions length less than one screen

- Seperate hard-coded cuts into script file

- Use pull-request mode on git

- Document well the high-level bash file for work flow
