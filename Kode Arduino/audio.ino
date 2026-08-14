// starts to play the actual file in the actual folder
void startFolderPlay() {
  filecounts = myDFPlayer.readFileCountsInFolder(folder);
  myDFPlayer.playFolder(folder, file);
  playing = false;
}

void updateDFplayer()
{
    // check player status
  if (myDFPlayer.available()) {
    uint8_t type = myDFPlayer.readType();
    int value = myDFPlayer.read();

    switch (type) {
      case DFPlayerPlayFinished:

  if(shuffleMode)
  {
      file = random(1, filecounts + 1);
  }
  else
  {
      file++;
      if(file > filecounts)
          file = 1;
  }

  myDFPlayer.playFolder(folder, file);
  EEPROM.write(2, file);
  updateScreen = true;
  break;
      default:
        break;
    }
  } 

}