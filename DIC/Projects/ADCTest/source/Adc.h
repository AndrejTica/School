//! ADC.h
/*! A interface for the easy use of the ADC
 * @file Adc.h
 * @interface adc Adc.h
 * @author    Ingomar Mayer
 * @version   1.0
 * @date      2019
 */

#ifndef ADC_H
#define ADC_H

//! An enum for the ADC prescaler
typedef enum {
	ADC_P2,		//!< ADC clock divided by 2
	ADC_P4,		//!< ADC clock divided by 4
	ADC_P8,		//!< ADC clock divided by 8
	ADC_P16,	//!< ADC clock divided by 16
	ADC_P32,	//!< ADC clock divided by 32
	ADC_P64,	//!< ADC clock divided by 64
	ADC_P128	//!< ADC clock divided by 128
} TADCPrescaler;

//! An enum for the ADC reference voltage
typedef enum {
	ADC_RVOLTAGE_AREF,		//!< ADC reference voltage connected to the AREF pin
	ADC_RVOLTAGE_AVCC,		//!< ADC reference voltage connected to the AVCC pin
	ADC_RVOLTAGE_A11,		//!< ADC reference voltage connected to the internal 1.1 voltage supply
	ADC_RVOLTAGE_A256		//!< ADC reference voltage connected to the internal 2.56 voltage supply
} TADCRefVoltage;

//! initialize the analog digital converter
/*!
 * initialize the ADC given the reference voltage and the prescaler
 * @attention this function must be called before using any other ADC function 
 * @param refVoltage from type TADCRefVoltage used to set the desired reference Voltage used in the ADC progress
 * @param prescaler from type TADCPrescaler used to set the desired prescaler used in the ADC progress
 */
void initADC(TADCRefVoltage refVoltage, TADCPrescaler prescaler);

//! starts the ADC free run mode
/*!
 * this function will initialize the build in ADC free run mode
 * @attention before you can call this function initADC(); must be called!
 * @param adcPin used to select which pin should be digitalized
 */
void startADC_FreeRunMode(uint8_t adcPin);

//! starts an ADC request, waits and returns the result
/*!
 * this function will make an ADC request, wait until the process is finished and then return it
 * @attention before you can call this function initADC(); must be called!
 * @param adcPin used to select which pin should be digitalized
 * @return the value of the converter in uint16_t
 */
uint16_t analogRead(uint8_t adcPin);

//! starts an ADC request and the result will later be saved in the address given
/*!
 * this function will make an ADC request and without waiting return. The result will later be saved in the address given when the ADC process finished
 * @attention before you can call this function initADC(); must be called!
 * @param adcPin used to select which pin should be digitalized
 * @param *addressVar used to save the result later in this address
 */
void analogRead_v(uint8_t adcPin, uint16_t *addressVar);

//! starts a \a noiseless ADC request and the result will later be saved in the address given
/*!
 * this function will make an ADC request and without waiting return. This request will shutdown all the other internal modules to create a better result.
 * The result will later be saved in the address given when the ADC process finished
 * @attention before you can call this function initADC(); must be called!
 * @warning not working lol
 * @param adcPin used to select which pin should be digitalized
 * @param *addressVar used to save the result later in this address
 */
void analogRead_Noiseless(uint8_t adcPin, uint16_t *addressVar);

//! return the saved value from the ADC FRM
/*!
 * this function will get and return the result of the last ADC convert
 * @attention before you can call this function initADC(); must be called!
 * @return the value of the last ADC convert in uint16_t
 */
uint16_t analogRead_FreeRunMode();

//! stops the ADC free run mode
/*!
 * stops the active free run mode. It won't stop any ongoing converts
 */
void stopADC_FreeRunMode();

//! stops the ADC
/*!
 * stops the ADC and resetting all ADC registers to default (0x00).
 * this function is needed for saving power because the normal sleep or idle mode won't turn off the ADC module automatic
 */
void stopADC();

#endif


