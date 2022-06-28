/* ************************************************************************** */
/**

  @Company
    Universidade de Aveiro

  @File Name
    distance.h

  @Summary
    Header file for all functions associated with distance measuring.
 */
/* ************************************************************************** */

#ifndef _DISTANCE_H    /* Guard against multiple inclusion */
#define _DISTANCE_H

#include "adc/adc.h"

// Look up table values for the distances in the different regions
// From 100mm to 200mm
static float zone_1_vals[12] = {3.03,2.61,2.22,1.91,1.64,1.40,1.15,0.99,0.82,0.71,0.58,0.46};
// From 200mm to 400mm
static float zone_2_vals[22] = {2.67,2.48,2.39,2.11,1.99,1.86,1.68,1.57,1.46,1.35,1.24,1.17,1.06,0.98,0.92,0.86,0.80,0.74,0.67,0.60,0.54,0.48};
// From 400mm to 600mm
static float zone_3_vals[22] = {2.59,2.43,2.27,2.11,2.09,1.95,1.79,1.77,1.64,1.47,1.47,1.31,1.31,1.15,1.15,1.00,0.99,0.90,0.84,0.81,0.67,0.67};

/** @brief Linearizes a value that is between two points
 *
 *  @param upper Upper point value
 *         upper_x Upper point x
 *         lower Lower point value
 *         lower_x Lower point x
 *         val Value to be linearized
 *  
 *  @return Returns the X value of the linearized point
 */
float linearize(float upper, uint8_t upper_x, float lower, uint8_t lower_x, float val);


/** @brief Returns the current distance being measured by the distance sensor
 *
 *  @return Distance in mm
 */
float get_dist();

#endif
