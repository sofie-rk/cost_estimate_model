# Cost estimate model
Cost estimate model for a process design project.

## Summary
Each equipment is a object. The object is initialized by a name, size and size unit.

Cost model data is provided in the file cost_table.txt. This file contains parameters for the cost model, taking from "Chemical Engineering Design" by Sinnott and Towler.

The cost model used is: 
<img src="https://render.githubusercontent.com/render/math?math=C = a + bS^n">, where C is the cost, S is the size parameter and a, b, n are cost parameters for the given equipment.

Each equipment object contains: name, size, a, b, n, cost, successCalc.

The equipment in the process plant will be provided to the program by the file equipment.txt. This file contains the equipment name, size and size unit.

When the equipment object is initialized, the parameters a, b, n, cost and successCalc are calculated/initialized.

The result of each equipment cost estimation is printed in the console.

## To do:
Write the result to a text-file instead of console.

Make one overloaded console-log opertor with only the important information and one overloaded console-log opeartor which shows the entire calculation.

Estimate installed cost.

Cost escalation.

Make process plant object, containing all of the equipment objects.

