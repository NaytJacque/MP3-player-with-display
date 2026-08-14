void preivousButtonClicked()
{

  updateScreen = true;  
  if(inSideMenuSelection && sMenuSelection < 2)
  {
   sMenuSelection++;
  }
  else if(selection < 5 && sMenuSelection == 1)
  {
     selection++; 
  }
  else if(selection == 1 && volume < 30 &&sMenuSelection == 2 && !inSideMenuSelection)
  {
     volume++; 
  }
  else if(selection == 2 && eq < 5 && sMenuSelection == 2 && !inSideMenuSelection)
  {
     eq++; 
  }
  else if(selection == 3 && !shuffleMode && sMenuSelection == 2 && !inSideMenuSelection)
   {
      shuffleMode = true;
   }
}

void nextButtonClicked()
{
  updateScreen = true;  
  if(inSideMenuSelection && sMenuSelection > 1)
  {
   sMenuSelection--;  
  }
  else if(selection > 1 && sMenuSelection == 1)
  {
    selection--;  
  }
  else if(selection == 1 && volume > 0 &&sMenuSelection == 2)
  {
     volume--; 
  }
  else if(selection == 2 && eq > 0 && sMenuSelection == 2)
  {
     eq--; 
  }
  else if(selection == 3 && shuffleMode && sMenuSelection == 2)
  {
      shuffleMode = false;
  }
}

void playButtonClicked()
{
  //Selection button
  if(inSideMenuSelection)
  {
      inSideMenuSelection = false;
      updateScreen = true;
      delay(100);
  }
  else if(!inSideMenuSelection && sMenuSelection == 1)
  {
       if(selection == 1)
       {
        if(file > 1)
        {
         //previous audio
         if(shuffleMode){
            myDFPlayer.previous();
            file--;
         }
         else {
            myDFPlayer.previous();
            file --;
            normalFile = file;
         
         if(!playing)
            playing = true;
         EEPROM.write(2, file);
         }
        }
       }
       else if(selection == 2)
       {
         //pause / play
         if(playing)
         {
          myDFPlayer.pause();
         }
         else
         {
          myDFPlayer.start();
         }
         playing = !playing;
       }
       else if(selection == 3)
       {
         if(shuffleMode)
         {
            file = random(1, filecounts + 1);
            myDFPlayer.playFolder(folder, file);
         }
         else
         {
            file++;
            if(file > filecounts){
            file = 1;
            }
             normalFile = file;
             myDFPlayer.playFolder(folder, file);
             if(!playing)
             playing = true;

             EEPROM.write(2, file);
         }   
       }
       else if(selection == 4)
       {
         file = 1;
         myDFPlayer.playFolder(folder, file);
         EEPROM.write(2, file);
       }
       else if(selection == 5)
       {
         //back to side menu
         selection = 1;
         inSideMenuSelection = true;
       }
       updateScreen = true;
       delay(200);
      }
      else if(!inSideMenuSelection && sMenuSelection == 2)
      {
         if(selection == 1)
         {
               selection = 2;
               myDFPlayer.volume(volume);
               EEPROM.write(0, volume);
         }
         else if(selection == 2)
         {
               selection = 3;
               myDFPlayer.EQ(eq);
               EEPROM.write(1, eq);
         }
         else if(selection == 3)
         {
            selection = 5;
         }
         else if(selection == 5)
         {
               selection = 1;
               inSideMenuSelection = true;
         }

         updateScreen = true;
         delay(200);
      }

}
