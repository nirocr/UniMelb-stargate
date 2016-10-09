#ifndef SEQ_H
#define SEQ_H

/* System Wide definition for Control Period */
#define CONTROL_PERIOD		0.0666666
#define NAME    12

/* ATCU data structure */
typedef struct {
   unsigned int cmd;
   unsigned int last_cmd;
   unsigned int state;
   unsigned int state_summary;
   unsigned int mode;
   unsigned int internal;
   unsigned int az_internal;
   unsigned int el_internal;
   unsigned int extern_plug;
   unsigned int system_ok;
   unsigned int comm_errors;
   double up_time;
   unsigned int operation;
   unsigned char system_signals;
   double sample_period;
} atcu_struct;

/* Control Point data structure (written into by parser tasks) */
typedef struct type_cp_data_struct{
   unsigned int cmd;
   unsigned int mode;	   /* Mode of machine */
   /*unsigned int star_num; */  /* Star number ? */
   char name [NAME];
   double signal;          /* Signal strength */
   double velocity;	   /* Tacho */
   double az_cmd;
   double el_cmd;
   double ra_cmd;
   double dec_cmd;
   char wrap;
   double az_dem_rate;
   double el_dem_rate;
   double az_ramp_rate;
   double el_ramp_rate;
   double az_rate_offset;
   double el_rate_offset;
   unsigned int clobber_watchdog;
} cp_data_struct;

/* Axis data structure for azimuth and elevation */
typedef struct {
   double cmd;			/* 0-360 degree position commanded */
   char cmd_wrap;
   double cmd_absolute;		/* +-360 degree position */
   double msd_absolute;		/* Calibrated position */
   double precalib_msd;		/* Precalibrated position */
   double calib_correction;	/* Calibration correction */
   double msd;			/* Actual measured Position in 0-360 format */
   char msd_wrap;		/* position wrap CW or CCW */
   double err;			/* measured - command error */
   double dem_rate;
   double rate_volts;		/* Volts to be applied to drives */
   double msd_rate;             /* Actual rate of movement */
   unsigned int cmd_clip;	/* clipping commanded positions */
   unsigned int signals;
   unsigned int drive;		/* drive signals read in from drives */
   unsigned int state;
   unsigned int in_sw_limit;    /* 0 - no; 1 - CW/UP; 2 CCW/DOWN; */
   unsigned int finallimit;
   unsigned int power_on;
   unsigned int on_on;
   unsigned int stowpin;
   unsigned int control_code;
   int drive_fail;
} Axis;

/* Data structure written to drives */
typedef struct {
   char begin_trans;
   char signals;
   char az_dac_raw [2];
   char el_dac_raw [2];
} drive_out_struct;

/* Data structure from drives and encoders */
typedef struct {
   char begin_trans;
   char az_signals;
   char el_signals;
   char az_enc_raw [3];
   char el_enc_raw [3];
   char system_signals;
} drive_in_struct;


/*---- Stow position structure, stored in NVRAM */
typedef struct {
   double az;
   double el;
} stow_pos_struct;


typedef struct {
   double azv;	        /* open loop az step Volts */
   double elv;          /* open loop el step volts */
   double step_per;     /* Step period in seconds for open-loop tests */
} systemid_struct;

typedef struct {
   char	name[ 11 ];	/* NULL terminated 10 character name used by 
                           Operator to identify star. */
   double right_ascension;
   double declination;
   int epoch_mode;
} star_details_struct;


/* Axis definitions */
#define AZ_DRIVE 0
#define EL_DRIVE 1

/* Wrap definitions */
#define CW_WRAP		0
#define CCW_WRAP	1
#define SHORTEST_WRAP   2

/* Define ATCU Commands ( that come from remote computer ) */
#define IDLE_CMD	0
#define STOW_CMD	1
#define DRIVE_START_CMD	2
#define DRIVE_STOP_CMD	3
#define GO_CMD		4
#define HOLD_CMD	5
#define POWER_ON_CMD	6
#define POWER_OFF_CMD	7
#define LIGHTS_ON_CMD	8
#define LIGHTS_OFF_CMD	9
#define SCAN_ON_CMD 	10
#define SCAN_OFF_CMD 	11
#define DATA_ON_CMD 	12
#define DATA_OFF_CMD 	13

/* Define ATCU Modes */
#define LEOTRACK_MODE		0
#define STARTRACK_MODE		1
#define POSITION_MODE		2
#define POSITION_RADEC_MODE     3
#define RATE_MODE    		4
#define INTELSAT_MODE		5
#define STEPTRACK_MODE		6
#define MANUALTRACK_MODE	7
#define KALMANTRACK_MODE 	8
#define TOTAL_MODES    KALMANTRACK_MODE

/* ATCU Internal States */
/* Define ATCU States */
#define OFF_STATE		0
#define HOLDING			1
#define STOWING			2
#define STARTING		3
#define STOPPING		4
#define STANDBY			5

#define TRACKING		6
#define SLEWING			7
#define STOWED			8
#define POSITIONING 		9

#define SCANNING		10
#define EXTERNAL		11
#define IDLE			12
#define RESET_DRIVES 		13
#define RESETTING_DRIVES	14
#define CHECKING_READY_ON	15
#define DRIVE_START_PULSE	16
#define START_PULSE		17
#define CHECK_ON		18
#define CHECK_READY_AGAIN	19
#define ENABLE_DRIVES		20
#define DRIVES_ENABLED		21

#define HOLD			22
#define DRIVING_TO_STOW		23
#define I_EXTERNAL		24
#define DRIVE_ENABLE		25
#define SLEWING_IN_POSITION     26
#define SLEWING_IN_TRACKING     27
#define SLEWING_IN_WAITING      28
#define WAITING_FOR_SOURCE      29
#define WAIT_FOR_READY		30
#define END_OF_STOW		31
#define POWERING_ON		32

/* Holding Definitions */
#define STOWING_TIME 		10000
#define HOLDING_TIME 		600
#define SLEW_ERROR		1.0	/* was 0.1 LJS 6-May-1992 */
#define TRACKING_ERROR		0.2
#define HOLDING_ERROR 		2.0
#define HOLDING_IN_REGION_TIME 	100
#define TRACKING_IN_REGION_TIME 5
#define WAIT_FOR_READY_ON_RESET 150

/* Power On Time-out. Count */
#define POWERON_TIMEOUT		60

/* Define opartional modes for ATCU */
#define SIMULATION 1
#define REAL_PLANT 0

/* Software Limits */
#define AZ_CW_LIMIT     270
#define AZ_CCW_LIMIT    -270

#define CW_LIMIT	1
#define CCW_LIMIT	2

#define EL_UP_LIMIT	91
#define EL_DOWN_LIMIT	-20

#define UP_LIMIT		1
#define DOWN_LIMIT		2

#define AZ_RAMP_RATE_MAX	 1.0
#define AZ_RAMP_RATE_MIN	 -1.0
#define EL_RAMP_RATE_MAX	 1.0
#define EL_RAMP_RATE_MIN	 -1.0


/* Prelimit definitions */
#define AZ_PRELIMIT_CW	        1
#define AZ_PRELIMIT_CCW		2

#define EL_PRELIMIT_UP		1
#define EL_PRELIMIT_DWN 	2

/* Stow positions */
#define AZ_STOW			7.0
#define EL_STOW			90.0

/* Define control codes */
#define POSITION_RATE		0
#define RATE_ONLY		1

/* Antenna speed limits */
/* 10500 deg/sec */
#define MAX_POS_ANTENNA_SPEED		1000
#define MAX_NEG_ANTENNA_SPEED		-1000
#define MAX_POS_ANTENNA_SPEED_LOAD	1.0
#define MAX_NEG_ANTENNA_SPEED_LOAD	-1.0

/* Define bit definitions */
/* Byte 1 from simulator/Plant */
#define az_rdy1			0x1
#define az_rdy2			0x2
#define az_on1			0x4
#define az_on2			0x8
#define az_pl_cw		0x10
#define az_pl_ccw		0x20
#define az_stowpin		0x40
#define az_spare		0x80

/* Byte 2 from simulator/plant */
#define el_rdy1			0x1
#define el_rdy2			0x2
#define el_on1			0x4
#define el_on2			0x8
#define el_pl_up		0x10
#define el_pl_dwn		0x20
#define el_stowpin		0x40
#define el_spare		0x80

/* System Port Bit definitions */
#define system_ok_b		0x1
#define external_b		0x2

/* Drive signal Bit definitions */
#define reset_low	0x00
#define reset_high	0x01
#define stop_open	0x00
#define stop_closed	0x02
#define start_low	0x00
#define start_high	0x04
#define poweron		0x08
#define poweroff	0x00
#define lights_on	0x10
#define enable_on       0x20

/*
   Timer definitions
 */
#define SEQ_TIME	10
#define RESET_TIME	20

/* Allow 35 seconds to start the drives */
#define START_PULSE_TIME       	60


#define NUM_SATELLITES		10

typedef struct Site_struct {

   double latitude;
   double longitude;
   double altitude;

} SiteStruct;


/******************************** End on SEQ.INC *************************/


void init_sequencer_task (void);
void sequencer_task ();


#endif
