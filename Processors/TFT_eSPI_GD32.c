        ////////////////////////////////////////////////////
        //       TFT_eSPI generic driver functions        //
        ////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
// Global variables
////////////////////////////////////////////////////////////////////////////////////////

TFT_Interface _com = TFT_Interface();

#if defined(TOUCH)
spi_parameter_struct spi_config{SPI_MASTER,SPI_TRANSMODE_FULLDUPLEX,SPI_FRAMESIZE_8BIT,SPI_NSS_SOFT,SPI_ENDIAN_MSB,SPI_CK_PL_LOW_PH_1EDGE,SPI_PSC_64};

GD32_SPI touch_spi = GD32_SPI(TOUCH_SPI, TOUCH_CS, TOUCH_SCK, TOUCH_MISO,
                              TOUCH_MOSI, &spi_config);
#endif

/***************************************************************************************
** Function name:           pushBlock - for STM32
** Description:             Write a block of pixels of the same colour
***************************************************************************************/
void TFT_eSPI::pushBlock(uint16_t color, uint32_t len){

  while ( len-- ) {tft_Write_16(color);}
}

/***************************************************************************************
** Function name:           pushPixels - for STM32
** Description:             Write a sequence of pixels
***************************************************************************************/
void TFT_eSPI::pushPixels(const void* data_in, uint32_t len){

  uint16_t *data = (uint16_t*)data_in;

  if (_swapBytes) while ( len-- ) {tft_Write_16(*data); data++;}
  else while ( len-- ) {tft_Write_16S(*data); data++;}
}
