// Register names according to the datasheet.
// According to the InvenSense document 
// "MPU-6000 and MPU-6050 Register Map 
// and Descriptions Revision 3.2", there are no registers
// at 0x02 ... 0x18, but according other information 
// the registers in that unknown area are for gain 
// and offsets.
// 
#define  AUX_VDDIO          0x01   // R/W
#define  SMPLRT_DIV         0x19   // R/W
#define  CONFIG             0x1A   // R/W
#define  GYRO_CONFIG        0x1B   // R/W
#define  ACCEL_CONFIG       0x1C   // R/W
#define  FF_THR             0x1D   // R/W
#define  FF_DUR             0x1E   // R/W
#define  MOT_THR            0x1F   // R/W
#define  MOT_DUR            0x20   // R/W
#define  ZRMOT_THR          0x21   // R/W
#define  ZRMOT_DUR          0x22   // R/W
#define  FIFO_EN            0x23   // R/W
#define  I2C_MST_CTRL       0x24   // R/W
#define  I2C_SLV0_ADDR      0x25   // R/W
#define  I2C_SLV0_REG       0x26   // R/W
#define  I2C_SLV0_CTRL      0x27   // R/W
#define  I2C_SLV1_ADDR      0x28   // R/W
#define  I2C_SLV1_REG       0x29   // R/W
#define  I2C_SLV1_CTRL      0x2A   // R/W
#define  I2C_SLV2_ADDR      0x2B   // R/W
#define  I2C_SLV2_REG       0x2C   // R/W
#define  I2C_SLV2_CTRL      0x2D   // R/W
#define  I2C_SLV3_ADDR      0x2E   // R/W
#define  I2C_SLV3_REG       0x2F   // R/W
#define  I2C_SLV3_CTRL      0x30   // R/W
#define  I2C_SLV4_ADDR      0x31   // R/W
#define  I2C_SLV4_REG       0x32   // R/W
#define  I2C_SLV4_DO        0x33   // R/W
#define  I2C_SLV4_CTRL      0x34   // R/W
#define  I2C_SLV4_DI        0x35   // R  
#define  I2C_MST_STATUS     0x36   // R
#define  INT_PIN_CFG        0x37   // R/W
#define  INT_ENABLE         0x38   // R/W
#define  INT_STATUS         0x3A   // R  
#define  ACCEL_XOUT_H       0x3B   // R  
#define  ACCEL_XOUT_L       0x3C   // R  
#define  ACCEL_YOUT_H       0x3D   // R  
#define  ACCEL_YOUT_L       0x3E   // R  
#define  ACCEL_ZOUT_H       0x3F   // R  
#define  ACCEL_ZOUT_L       0x40   // R  
#define  TEMP_OUT_H         0x41   // R  
#define  TEMP_OUT_L         0x42   // R  
#define  GYRO_XOUT_H        0x43   // R  
#define  GYRO_XOUT_L        0x44   // R  
#define  GYRO_YOUT_H        0x45   // R  
#define  GYRO_YOUT_L        0x46   // R  
#define  GYRO_ZOUT_H        0x47   // R  
#define  GYRO_ZOUT_L        0x48   // R  
#define  EXT_SENS_DATA_00   0x49   // R  
#define  EXT_SENS_DATA_01   0x4A   // R  
#define  EXT_SENS_DATA_02   0x4B   // R  
#define  EXT_SENS_DATA_03   0x4C   // R  
#define  EXT_SENS_DATA_04   0x4D   // R  
#define  EXT_SENS_DATA_05   0x4E   // R  
#define  EXT_SENS_DATA_06   0x4F   // R  
#define  EXT_SENS_DATA_07   0x50   // R  
#define  EXT_SENS_DATA_08   0x51   // R  
#define  EXT_SENS_DATA_09   0x52   // R  
#define  EXT_SENS_DATA_10   0x53   // R  
#define  EXT_SENS_DATA_11   0x54   // R  
#define  EXT_SENS_DATA_12   0x55   // R  
#define  EXT_SENS_DATA_13   0x56   // R  
#define  EXT_SENS_DATA_14   0x57   // R  
#define  EXT_SENS_DATA_15   0x58   // R  
#define  EXT_SENS_DATA_16   0x59   // R  
#define  EXT_SENS_DATA_17   0x5A   // R  
#define  EXT_SENS_DATA_18   0x5B   // R  
#define  EXT_SENS_DATA_19   0x5C   // R  
#define  EXT_SENS_DATA_20   0x5D   // R  
#define  EXT_SENS_DATA_21   0x5E   // R  
#define  EXT_SENS_DATA_22   0x5F   // R  
#define  EXT_SENS_DATA_23   0x60   // R  
#define  MOT_DETECT_STATUS  0x61   // R  
#define  I2C_SLV0_DO        0x63   // R/W
#define  I2C_SLV1_DO        0x64   // R/W
#define  I2C_SLV2_DO        0x65   // R/W
#define  I2C_SLV3_DO        0x66   // R/W
#define  I2C_MST_DELAY_CTRL 0x67   // R/W
#define  SIGNAL_PATH_RESET  0x68   // R/W
#define  MOT_DETECT_CTRL    0x69   // R/W
#define  USER_CTRL          0x6A   // R/W
#define  PWR_MGMT_1         0x6B   // R/W
#define  PWR_MGMT_2         0x6C   // R/W
#define  FIFO_COUNTH        0x72   // R/W
#define  FIFO_COUNTL        0x73   // R/W
#define  FIFO_R_W           0x74   // R/W
#define  WHO_AM_I           0x75   // R


// Defines for the bits, to be able to change 
// between bit number and binary definition.
// By using the bit number, programming the sensor 
// is like programming the AVR microcontroller.
// But instead of using "(1<<X)", or "_BV(X)", 
// the Arduino "bit(X)" is used.
#define  D0 0
#define  D1 1
#define  D2 2
#define  D3 3
#define  D4 4
#define  D5 5
#define  D6 6
#define  D7 7

// AUX_VDDIO Register
//#define  AUX_VDDIO  D7  // I2C high: 1=VDD, 0=VLOGIC

// CONFIG Register
// DLPF is Digital Low Pass Filter for both gyro and accelerometers.
// These are the names for the bits.
// Use these only with the bit() macro.
#define  DLPF_CFG0      D0
#define  DLPF_CFG1      D1
#define  DLPF_CFG2      D2
#define  EXT_SYNC_SET0  D3
#define  EXT_SYNC_SET1  D4
#define  EXT_SYNC_SET2  D5

// Combined definitions for the EXT_SYNC_SET values
#define  EXT_SYNC_SET_0 (0)
#define  EXT_SYNC_SET_1 (bit( EXT_SYNC_SET0))
#define  EXT_SYNC_SET_2 (bit( EXT_SYNC_SET1))
#define  EXT_SYNC_SET_3 (bit( EXT_SYNC_SET1)|bit( EXT_SYNC_SET0))
#define  EXT_SYNC_SET_4 (bit( EXT_SYNC_SET2))
#define  EXT_SYNC_SET_5 (bit( EXT_SYNC_SET2)|bit( EXT_SYNC_SET0))
#define  EXT_SYNC_SET_6 (bit( EXT_SYNC_SET2)|bit( EXT_SYNC_SET1))
#define  EXT_SYNC_SET_7 (bit( EXT_SYNC_SET2)|bit( EXT_SYNC_SET1)|bit( EXT_SYNC_SET0))

// Alternative names for the combined definitions.
#define  EXT_SYNC_DISABLED      EXT_SYNC_SET_0
#define  EXT_SYNC_TEMP_OUT_L    EXT_SYNC_SET_1
#define  EXT_SYNC_GYRO_XOUT_L   EXT_SYNC_SET_2
#define  EXT_SYNC_GYRO_YOUT_L   EXT_SYNC_SET_3
#define  EXT_SYNC_GYRO_ZOUT_L   EXT_SYNC_SET_4
#define  EXT_SYNC_ACCEL_XOUT_L  EXT_SYNC_SET_5
#define  EXT_SYNC_ACCEL_YOUT_L  EXT_SYNC_SET_6
#define  EXT_SYNC_ACCEL_ZOUT_L  EXT_SYNC_SET_7

// Combined definitions for the DLPF_CFG values
#define  DLPF_CFG_0 (0)
#define  DLPF_CFG_1 (bit( DLPF_CFG0))
#define  DLPF_CFG_2 (bit( DLPF_CFG1))
#define  DLPF_CFG_3 (bit( DLPF_CFG1)|bit( DLPF_CFG0))
#define  DLPF_CFG_4 (bit( DLPF_CFG2))
#define  DLPF_CFG_5 (bit( DLPF_CFG2)|bit( DLPF_CFG0))
#define  DLPF_CFG_6 (bit( DLPF_CFG2)|bit( DLPF_CFG1))
#define  DLPF_CFG_7 (bit( DLPF_CFG2)|bit( DLPF_CFG1)|bit( DLPF_CFG0))

// Alternative names for the combined definitions
// This name uses the bandwidth (Hz) for the accelometer,
// for the gyro the bandwidth is almost the same.
#define  DLPF_260HZ     DLPF_CFG_0
#define  DLPF_184HZ     DLPF_CFG_1
#define  DLPF_94HZ      DLPF_CFG_2
#define  DLPF_44HZ      DLPF_CFG_3
#define  DLPF_21HZ      DLPF_CFG_4
#define  DLPF_10HZ      DLPF_CFG_5
#define  DLPF_5HZ       DLPF_CFG_6
#define  DLPF_RESERVED  DLPF_CFG_7

// GYRO_CONFIG Register
// The XG_ST, YG_ST, ZG_ST are bits for selftest.
// The FS_SEL sets the range for the gyro.
// These are the names for the bits.
// Use these only with the bit() macro.
#define  FS_SEL0  D3
#define  FS_SEL1  D4
#define  ZG_ST    D5
#define  YG_ST    D6
#define  XG_ST    D7

// Combined definitions for the FS_SEL values
#define  FS_SEL_0 (0)
#define  FS_SEL_1 (bit( FS_SEL0))
#define  FS_SEL_2 (bit( FS_SEL1))
#define  FS_SEL_3 (bit( FS_SEL1)|bit( FS_SEL0))

// Alternative names for the combined definitions
// The name uses the range in degrees per second.
#define  FS_SEL_250   FS_SEL_0
#define  FS_SEL_500   FS_SEL_1
#define  FS_SEL_1000  FS_SEL_2
#define  FS_SEL_2000  FS_SEL_3

// ACCEL_CONFIG Register
// The XA_ST, YA_ST, ZA_ST are bits for selftest.
// The AFS_SEL sets the range for the accelerometer.
// These are the names for the bits.
// Use these only with the bit() macro.
#define  ACCEL_HPF0  D0
#define  ACCEL_HPF1  D1
#define  ACCEL_HPF2  D2
#define  AFS_SEL0    D3
#define  AFS_SEL1    D4
#define  ZA_ST       D5
#define  YA_ST       D6
#define  XA_ST       D7

// Combined definitions for the ACCEL_HPF values
#define  ACCEL_HPF_0 (0)
#define  ACCEL_HPF_1 (bit( ACCEL_HPF0))
#define  ACCEL_HPF_2 (bit( ACCEL_HPF1))
#define  ACCEL_HPF_3 (bit( ACCEL_HPF1)|bit( ACCEL_HPF0))
#define  ACCEL_HPF_4 (bit( ACCEL_HPF2))
#define  ACCEL_HPF_7 (bit( ACCEL_HPF2)|bit( ACCEL_HPF1)|bit( ACCEL_HPF0))

// Alternative names for the combined definitions
// The name uses the Cut-off frequency.
#define  ACCEL_HPF_RESET   ACCEL_HPF_0
#define  ACCEL_HPF_5HZ     ACCEL_HPF_1
#define  ACCEL_HPF_2_5HZ   ACCEL_HPF_2
#define  ACCEL_HPF_1_25HZ  ACCEL_HPF_3
#define  ACCEL_HPF_0_63HZ  ACCEL_HPF_4
#define  ACCEL_HPF_HOLD    ACCEL_HPF_7

// Combined definitions for the AFS_SEL values
#define  AFS_SEL_0 (0)
#define  AFS_SEL_1 (bit( AFS_SEL0))
#define  AFS_SEL_2 (bit( AFS_SEL1))
#define  AFS_SEL_3 (bit( AFS_SEL1)|bit( AFS_SEL0))

// Alternative names for the combined definitions
// The name uses the full scale range for the accelerometer.
#define  AFS_SEL_2G   AFS_SEL_0
#define  AFS_SEL_4G   AFS_SEL_1
#define  AFS_SEL_8G   AFS_SEL_2
#define  AFS_SEL_16G  AFS_SEL_3

// FIFO_EN Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  SLV0_FIFO_EN   D0
#define  SLV1_FIFO_EN   D1
#define  SLV2_FIFO_EN   D2
#define  ACCEL_FIFO_EN  D3
#define  ZG_FIFO_EN     D4
#define  YG_FIFO_EN     D5
#define  XG_FIFO_EN     D6
#define  TEMP_FIFO_EN   D7

// I2C_MST_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_MST_CLK0   D0
#define  I2C_MST_CLK1   D1
#define  I2C_MST_CLK2   D2
#define  I2C_MST_CLK3   D3
#define  I2C_MST_P_NSR  D4
#define  SLV_3_FIFO_EN  D5
#define  WAIT_FOR_ES    D6
#define  MULT_MST_EN    D7

// Combined definitions for the I2C_MST_CLK
#define  I2C_MST_CLK_0 (0)
#define  I2C_MST_CLK_1  (bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_2  (bit( I2C_MST_CLK1))
#define  I2C_MST_CLK_3  (bit( I2C_MST_CLK1)|bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_4  (bit( I2C_MST_CLK2))
#define  I2C_MST_CLK_5  (bit( I2C_MST_CLK2)|bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_6  (bit( I2C_MST_CLK2)|bit( I2C_MST_CLK1))
#define  I2C_MST_CLK_7  (bit( I2C_MST_CLK2)|bit( I2C_MST_CLK1)|bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_8  (bit( I2C_MST_CLK3))
#define  I2C_MST_CLK_9  (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_10 (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK1))
#define  I2C_MST_CLK_11 (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK1)|bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_12 (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK2))
#define  I2C_MST_CLK_13 (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK2)|bit( I2C_MST_CLK0))
#define  I2C_MST_CLK_14 (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK2)|bit( I2C_MST_CLK1))
#define  I2C_MST_CLK_15 (bit( I2C_MST_CLK3)|bit( I2C_MST_CLK2)|bit( I2C_MST_CLK1)|bit( I2C_MST_CLK0))

// Alternative names for the combined definitions
// The names uses I2C Master Clock Speed in kHz.
#define  I2C_MST_CLK_348KHZ  I2C_MST_CLK_0
#define  I2C_MST_CLK_333KHZ  I2C_MST_CLK_1
#define  I2C_MST_CLK_320KHZ  I2C_MST_CLK_2
#define  I2C_MST_CLK_308KHZ  I2C_MST_CLK_3
#define  I2C_MST_CLK_296KHZ  I2C_MST_CLK_4
#define  I2C_MST_CLK_286KHZ  I2C_MST_CLK_5
#define  I2C_MST_CLK_276KHZ  I2C_MST_CLK_6
#define  I2C_MST_CLK_267KHZ  I2C_MST_CLK_7
#define  I2C_MST_CLK_258KHZ  I2C_MST_CLK_8
#define  I2C_MST_CLK_500KHZ  I2C_MST_CLK_9
#define  I2C_MST_CLK_471KHZ  I2C_MST_CLK_10
#define  I2C_MST_CLK_444KHZ  I2C_MST_CLK_11
#define  I2C_MST_CLK_421KHZ  I2C_MST_CLK_12
#define  I2C_MST_CLK_400KHZ  I2C_MST_CLK_13
#define  I2C_MST_CLK_381KHZ  I2C_MST_CLK_14
#define  I2C_MST_CLK_364KHZ  I2C_MST_CLK_15

// I2C_SLV0_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV0_RW  D7

// I2C_SLV0_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV0_LEN0     D0
#define  I2C_SLV0_LEN1     D1
#define  I2C_SLV0_LEN2     D2
#define  I2C_SLV0_LEN3     D3
#define  I2C_SLV0_GRP      D4
#define  I2C_SLV0_REG_DIS  D5
#define  I2C_SLV0_BYTE_SW  D6
#define  I2C_SLV0_EN       D7

// A mask for the length
#define  I2C_SLV0_LEN_MASK 0x0F

// I2C_SLV1_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV1_RW  D7

// I2C_SLV1_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV1_LEN0     D0
#define  I2C_SLV1_LEN1     D1
#define  I2C_SLV1_LEN2     D2
#define  I2C_SLV1_LEN3     D3
#define  I2C_SLV1_GRP      D4
#define  I2C_SLV1_REG_DIS  D5
#define  I2C_SLV1_BYTE_SW  D6
#define  I2C_SLV1_EN       D7

// A mask for the length
#define  I2C_SLV1_LEN_MASK 0x0F

// I2C_SLV2_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV2_RW  D7

// I2C_SLV2_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV2_LEN0     D0
#define  I2C_SLV2_LEN1     D1
#define  I2C_SLV2_LEN2     D2
#define  I2C_SLV2_LEN3     D3
#define  I2C_SLV2_GRP      D4
#define  I2C_SLV2_REG_DIS  D5
#define  I2C_SLV2_BYTE_SW  D6
#define  I2C_SLV2_EN       D7

// A mask for the length
#define  I2C_SLV2_LEN_MASK 0x0F

// I2C_SLV3_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV3_RW  D7

// I2C_SLV3_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV3_LEN0     D0
#define  I2C_SLV3_LEN1     D1
#define  I2C_SLV3_LEN2     D2
#define  I2C_SLV3_LEN3     D3
#define  I2C_SLV3_GRP      D4
#define  I2C_SLV3_REG_DIS  D5
#define  I2C_SLV3_BYTE_SW  D6
#define  I2C_SLV3_EN       D7

// A mask for the length
#define  I2C_SLV3_LEN_MASK 0x0F

// I2C_SLV4_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV4_RW  D7

// I2C_SLV4_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_MST_DLY0      D0
#define  I2C_MST_DLY1      D1
#define  I2C_MST_DLY2      D2
#define  I2C_MST_DLY3      D3
#define  I2C_MST_DLY4      D4
#define  I2C_SLV4_REG_DIS  D5
#define  I2C_SLV4_INT_EN   D6
#define  I2C_SLV4_EN       D7

// A mask for the delay
#define  I2C_MST_DLY_MASK 0x1F

// I2C_MST_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV0_NACK  D0
#define  I2C_SLV1_NACK  D1
#define  I2C_SLV2_NACK  D2
#define  I2C_SLV3_NACK  D3
#define  I2C_SLV4_NACK  D4
#define  I2C_LOST_ARB   D5
#define  I2C_SLV4_DONE  D6
#define  PASS_THROUGH   D7

// I2C_PIN_CFG Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  CLKOUT_EN        D0
#define  I2C_BYPASS_EN    D1
#define  FSYNC_INT_EN     D2
#define  FSYNC_INT_LEVEL  D3
#define  INT_RD_CLEAR     D4
#define  LATCH_INT_EN     D5
#define  INT_OPEN         D6
#define  INT_LEVEL        D7

// INT_ENABLE Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  DATA_RDY_EN     D0
#define  I2C_MST_INT_EN  D3
#define  FIFO_OFLOW_EN   D4
#define  ZMOT_EN         D5
#define  MOT_EN          D6
#define  FF_EN           D7

// INT_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  DATA_RDY_INT    D0
#define  I2C_MST_INT     D3
#define  FIFO_OFLOW_INT  D4
#define  ZMOT_INT        D5
#define  MOT_INT         D6
#define  FF_INT          D7

// MOT_DETECT_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  MOT_ZRMOT  D0
#define  MOT_ZPOS   D2
#define  MOT_ZNEG   D3
#define  MOT_YPOS   D4
#define  MOT_YNEG   D5
#define  MOT_XPOS   D6
#define  MOT_XNEG   D7

// IC2_MST_DELAY_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  I2C_SLV0_DLY_EN  D0
#define  I2C_SLV1_DLY_EN  D1
#define  I2C_SLV2_DLY_EN  D2
#define  I2C_SLV3_DLY_EN  D3
#define  I2C_SLV4_DLY_EN  D4
#define  DELAY_ES_SHADOW  D7

// SIGNAL_PATH_RESET Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  TEMP_RESET   D0
#define  ACCEL_RESET  D1
#define  GYRO_RESET   D2

// MOT_DETECT_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  MOT_COUNT0       D0
#define  MOT_COUNT1       D1
#define  FF_COUNT0        D2
#define  FF_COUNT1        D3
#define  ACCEL_ON_DELAY0  D4
#define  ACCEL_ON_DELAY1  D5

// Combined definitions for the MOT_COUNT
#define  MOT_COUNT_0 (0)
#define  MOT_COUNT_1 (bit( MOT_COUNT0))
#define  MOT_COUNT_2 (bit( MOT_COUNT1))
#define  MOT_COUNT_3 (bit( MOT_COUNT1)|bit( MOT_COUNT0))

// Alternative names for the combined definitions
#define  MOT_COUNT_RESET  MOT_COUNT_0

// Combined definitions for the FF_COUNT
#define  FF_COUNT_0 (0)
#define  FF_COUNT_1 (bit( FF_COUNT0))
#define  FF_COUNT_2 (bit( FF_COUNT1))
#define  FF_COUNT_3 (bit( FF_COUNT1)|bit( FF_COUNT0))

// Alternative names for the combined definitions
#define  FF_COUNT_RESET  FF_COUNT_0

// Combined definitions for the ACCEL_ON_DELAY
#define  ACCEL_ON_DELAY_0 (0)
#define  ACCEL_ON_DELAY_1 (bit( ACCEL_ON_DELAY0))
#define  ACCEL_ON_DELAY_2 (bit( ACCEL_ON_DELAY1))
#define  ACCEL_ON_DELAY_3 (bit( ACCEL_ON_DELAY1)|bit( ACCEL_ON_DELAY0))

// Alternative names for the ACCEL_ON_DELAY
#define  ACCEL_ON_DELAY_0MS  ACCEL_ON_DELAY_0
#define  ACCEL_ON_DELAY_1MS  ACCEL_ON_DELAY_1
#define  ACCEL_ON_DELAY_2MS  ACCEL_ON_DELAY_2
#define  ACCEL_ON_DELAY_3MS  ACCEL_ON_DELAY_3

// USER_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  SIG_COND_RESET  D0
#define  I2C_MST_RESET   D1
#define  FIFO_RESET      D2
#define  I2C_IF_DIS      D4   // must be 0 for MPU-6050
#define  I2C_MST_EN      D5
//#define  FIFO_EN         D6

// PWR_MGMT_1 Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  CLKSEL0       D0
#define  CLKSEL1       D1
#define  CLKSEL2       D2
#define  TEMP_DIS      D3    // 1: disable temperature sensor
#define  CYCLE         D5    // 1: sample and sleep
#define  SLEEP         D6    // 1: sleep mode
#define  DEVICE_RESET  D7    // 1: reset to default values

// Combined definitions for the CLKSEL
#define  CLKSEL_0 (0)
#define  CLKSEL_1 (bit( CLKSEL0))
#define  CLKSEL_2 (bit( CLKSEL1))
#define  CLKSEL_3 (bit( CLKSEL1)|bit( CLKSEL0))
#define  CLKSEL_4 (bit( CLKSEL2))
#define  CLKSEL_5 (bit( CLKSEL2)|bit( CLKSEL0))
#define  CLKSEL_6 (bit( CLKSEL2)|bit( CLKSEL1))
#define  CLKSEL_7 (bit( CLKSEL2)|bit( CLKSEL1)|bit( CLKSEL0))

// Alternative names for the combined definitions
#define  CLKSEL_INTERNAL     CLKSEL_0
#define  CLKSEL_X            CLKSEL_1
#define  CLKSEL_Y            CLKSEL_2
#define  CLKSEL_Z            CLKSEL_3
#define  CLKSEL_EXT_32KHZ    CLKSEL_4
#define  CLKSEL_EXT_19_2MHZ  CLKSEL_5
#define  CLKSEL_RESERVED     CLKSEL_6
#define  CLKSEL_STOP         CLKSEL_7

// PWR_MGMT_2 Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define  STBY_ZG        D0
#define  STBY_YG        D1
#define  STBY_XG        D2
#define  STBY_ZA        D3
#define  STBY_YA        D4
#define  STBY_XA        D5
#define  LP_WAKE_CTRL0  D6
#define  LP_WAKE_CTRL1  D7

// Combined definitions for the LP_WAKE_CTRL
#define  LP_WAKE_CTRL_0 (0)
#define  LP_WAKE_CTRL_1 (bit( LP_WAKE_CTRL0))
#define  LP_WAKE_CTRL_2 (bit( LP_WAKE_CTRL1))
#define  LP_WAKE_CTRL_3 (bit( LP_WAKE_CTRL1)|bit( LP_WAKE_CTRL0))

// Alternative names for the combined definitions
// The names uses the Wake-up Frequency.
#define  LP_WAKE_1_25HZ  LP_WAKE_CTRL_0
#define  LP_WAKE_2_5HZ   LP_WAKE_CTRL_1
#define  LP_WAKE_5HZ     LP_WAKE_CTRL_2
#define  LP_WAKE_10HZ    LP_WAKE_CTRL_3


// Default I2C address for the MPU-6050 is 0x68.
// But only if the AD0 pin is low.
// Some sensor boards have AD0 high, and the
// I2C address thus becomes 0x69.
#define  MPU6050_I2C_ADDRESS 0x68


// Declaring an union for the registers and the axis values.
// The byte order does not match the byte order of 
// the compiler and AVR chip.
// The AVR chip (on the Arduino board) has the Low Byte 
// at the lower address.
// But the MPU-6050 has a different order: High Byte at
// lower address, so that has to be corrected.
// The register part "reg" is only used internally, 
// and are swapped in code.

union data_6050 {
		struct regs
		{
			uint8_t x_accel_h;
			uint8_t x_accel_l;
			uint8_t y_accel_h;
			uint8_t y_accel_l;
			uint8_t z_accel_h;
			uint8_t z_accel_l;
			uint8_t t_h;
			uint8_t t_l;
			uint8_t x_gyro_h;
			uint8_t x_gyro_l;
			uint8_t y_gyro_h;
			uint8_t y_gyro_l;
			uint8_t z_gyro_h;
			uint8_t z_gyro_l;
}
		struct value {
			int16_t x_accel;
			int16_t y_accel;
			int16_t z_accel;
			int16_t temperature;
			int16_t x_gyro;
			int16_t y_gyro;
			int16_t z_gyro; 
			};
	};
	

