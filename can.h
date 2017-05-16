#ifndef CAN_H
#define CAN_H

extern void startCommunicationCanController(void);
extern void sendVoltageCan(int voltage);

#define CANSPEED_125 	7		// CAN speed at 125 kbps
#define CANSPEED_250  	3		// CAN speed at 250 kbps
#define CANSPEED_500	1	// CAN speed at 500 kbps

#endif
