//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//

#ifndef VARTOTOJOSASAJA_C_VARTOTOJOSASAJOSFUNKCIJOS_H
#define VARTOTOJOSASAJA_C_VARTOTOJOSASAJOSFUNKCIJOS_H

// shows menu and returns number of choice
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

// validates if input is integer and whether it falls into the given bounds, returns said input.
int intValidation(int lowerBound, int upperBound);



#endif //VARTOTOJOSASAJA_C_VARTOTOJOSASAJOSFUNKCIJOS_H
