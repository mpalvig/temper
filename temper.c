/*
 * Standalone temperature logger
 *
 */

#include <stdio.h>
#include "pcsensor.h"

/* Calibration adjustments */
/* See http://www.pitt-pladdy.com/blog/_20110824-191017_0100_TEMPer_under_Linux_perl_with_Cacti/ */
/*static float scale = 1.0287;*/
/*static float offset = -1.85;*/
static float scale =  0.9821;
static float offset = -0.60;

int main(){
	float tempc = 0.0000;
    int i;

    usb_dev_handle* lvr_winusb = pcsensor_open();
    if (!lvr_winusb) {
        /* Open fails sometime */
        printf("open failed\n");
		fflush(stdout);
        return 1;
    }

    for (i = 0; i < 40; ++i)
    {
        
        tempc = pcsensor_get_temperature(lvr_winusb);

        if (!(tempc > -0.0001 && tempc < 0.0001)) {
            /* Apply calibrations */
            tempc = (tempc * scale) + offset;

            printf("%f\n", tempc);
            fflush(stdout);

            /*return 0;*/
        }
        else {
            printf("Temperature is zero, probably error\n");
            fflush(stdout);
            /*return 2;*/
        }
        sleep(1);
    }
    pcsensor_close(lvr_winusb);
    return 0;

}
