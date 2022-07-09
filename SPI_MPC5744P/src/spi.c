/*****************************************************************************/
/* FILE NAME: spi.c                            COPYRIGHT (c) Freescale 2015  */
/*                                                      All Rights Reserved  */
/* DESCRIPTION: SPI functions for initialization and reading received data.  */
/*                                                                           */
/*****************************************************************************/	
/* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE                  */
/* ---   -----------    ----------    ---------------------                  */
/* 1.0	 Scott Obrien   21 Apr 2015   Initial Version                        */
/*****************************************************************************/

#include "project.h"
#include "spi.h"

unsigned int RecDataMaster=0;
unsigned int RecDataSlave=0;

/*****************************************************************************/
/* Check RM for available pinout options. Connect SOUT_Master to SIN_Slave and SIN_Master to SOUT_Slave
** 
** DSPI_1 MASTER
** CLK	  PA6
** SOUT	  PA7
** SIN	  PA8
** SS/CS0 PA5
**
** DSPI_2  SLAVE
** CLK	  PA0
** SOUT	  PA1
** SIN	  PA2
** SS/CS0 PA3
*/
/*****************************************************************************/

void init_dspi_ports()
{
  /* Master - DSPI_1 */
  SIUL2.MSCR[PA7].B.SSS = 1;                 /* Pad PA7: Source signal is DSPI_1 SOUT  */
  SIUL2.MSCR[PA7].B.OBE = 1;                 /* Pad PA7: OBE=1. */
  SIUL2.MSCR[PA7].B.SRC = 3;                 /* Pad PA7: Full strength slew rate */
  
  SIUL2.MSCR[PA6].B.SSS = 1;                /* Pad PA6: Source signal is DSPI_1 CLK  */
  SIUL2.MSCR[PA6].B.OBE = 1;                /* Pad PA6: OBE=1. */
  SIUL2.MSCR[PA6].B.SRC = 3;                /* Pad PA6: Full strength slew rate */
  
  SIUL2.MSCR[PA8].B.IBE = 1;                /* Pad PA8: Enable pad for input DSPI_1 SIN */
  SIUL2.IMCR[44].B.SSS = 1;            		/* Pad PA8: connected to pad PA8 */

  SIUL2.MSCR[PA5].B.SSS = 1;                 /* Pad PA5: Source signal is DSPI_1 CS0  */
  SIUL2.MSCR[PA5].B.OBE = 1;                 /* Pad PA5: OBE=1. */
  SIUL2.MSCR[PA5].B.SRC = 3;                 /* Pad PA5: Full strength slew rate */
  
  /* Slave - DSPI_2 */
  SIUL2.MSCR[PA0].B.SSS = 2;                /* Pad PA0: Source signal is DSPI_2 CLK */
  SIUL2.MSCR[PA0].B.IBE = 1;                /* Pad PA0: IBE=1. */
  SIUL2.IMCR[48].B.SSS = 1; 	           /* Pad PA0: DSPI_2 CLK. Slave takes clock from master. Therefore input */
  
  SIUL2.MSCR[PA1].B.SSS = 2;                /* Pad PA1: Source signal is DSPI_2 SOUT */
  SIUL2.MSCR[PA1].B.OBE = 1;                /* Pad PA1: OBE=1. */
  SIUL2.MSCR[PA1].B.SRC = 3;                /* Pad PA1: Full strength slew rate */
  
  SIUL2.MSCR[PA2].B.IBE = 1;                /* Pad PA2: Enable pad for input DSPI_2 SIN */
  SIUL2.IMCR[47].B.SSS = 2;            /* Pad PA2: connected to pad */

  SIUL2.MSCR[PA3].B.IBE = 1;                /* Pad PA3: IBE=1. DSPI_2 SS */
  SIUL2.IMCR[49].B.SSS = 1;            /* Pad PA3: connected to pad */
}

/*****************************************************************************/

void init_dspi_1(void)
{
  SPI_1.MCR.R = 0x80010001;                /* Configure DSPI_1 as master */
  SPI_1.MODE.CTAR[0].R = 0x78021004;       /* Configure CTAR0  */
  SPI_1.MCR.B.HALT = 0x0;                  /* Exit HALT mode: go from STOPPED to RUNNING state*/
}

void init_dspi_2(void)
{
	SPI_2.MCR.R = 0x00010001;                 /* Configure DSPI_1 as slave */
	SPI_2.MODE.CTAR[0].R = 0x78021004;        /* Configure CTAR0  */
	SPI_2.MCR.B.HALT = 0x0;                   /* Exit HALT mode: go from STOPPED to RUNNING state*/
}

void read_data_DSPI_1(void) {
  while (SPI_1.SR.B.RFDF != 1){}           /* Wait for Receive FIFO Drain Flag = 1 */
  RecDataMaster = SPI_1.POPR.R;             /* Read data received by master SPI */
  SPI_1.SR.R = 0xFCFE0000;                 /* Clear ALL status flags by writing 1 to them */
}

void read_data_DSPI_2(void) {
  while (SPI_2.SR.B.RFDF != 1){}            /* Wait for Receive FIFO Drain Flag = 1 */
  RecDataSlave = SPI_2.POPR.R;             /* Read data received by slave SPI */
  SPI_2.SR.R = 0xFCFE0000;                  /* Clear ALL status flags by writing 1 */
}

/*****************************************************************************/
