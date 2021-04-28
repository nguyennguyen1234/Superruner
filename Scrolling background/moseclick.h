//The mouse button
class LButton
{
	public:
		//Initializes internal variables
		LButton();

		//Sets top left position
		void setPosition( int x, int y );

		//Handles mouse event
		void handleEvent( SDL_Event e );

		//Shows button sprite
		void render();

	private:
		//Top left position
		SDL_Point mPosition;

};


//Buttons objects
LButton gButtons;
//check mouse event
bool mouse =true;
// control sound var
bool sound =true;
//run check
bool run=false;
bool help=false;
bool checkquit=false;
bool resume=false;
bool checkresume=false;
bool checkclick=  false;
bool reset=false;

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;

}


void LButton::handleEvent( SDL_Event e )
{
	 if( e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        //Get mouse position
                        int mx, my;
                        SDL_GetMouseState( &mx, &my );
                        if(mx>=55&&mx<=110&&my>=5&&my<=52)
                        {
                            if(sound==true)sound=false;
                            else if (sound==false) sound=true;
                        }

                        // Get play button
                        if (mx>=SCREEN_WIDTH*0.43&&mx<=SCREEN_WIDTH*0.43+300&&my>=SCREEN_HEIGHT*0.4&&my<=SCREEN_HEIGHT*0.4+93&&!checkclick)
                        {
                            mouse=false;
                            run=true;
                            resume=false;
                            checkclick=true;
                        }
                        //Get helps button
                        if (mx>=SCREEN_WIDTH*0.43&&mx<=SCREEN_WIDTH*0.43+300&&my>=SCREEN_HEIGHT*0.4+130&&my<=SCREEN_HEIGHT*0.4+223&&!checkclick)
                        {
                            help=true;
                            mouse=false;
                            resume=false;
                            checkclick=true;
                        }

                        //Get exit button
                        if (mx>=SCREEN_WIDTH*0.43&&mx<=SCREEN_WIDTH*0.43+300&&my>=SCREEN_HEIGHT*0.4+260&&my<=SCREEN_HEIGHT*0.4+353&&!checkclick)
                        {
                            mouse=false;
                            checkquit=true;
                        }
                        //get X click
                        if (mx>=SCREEN_WIDTH*0.25+SCREEN_WIDTH/2-110&&mx<=SCREEN_WIDTH*0.25+SCREEN_WIDTH/2-50&&my>=SCREEN_HEIGHT*0.1+100&&my<=SCREEN_HEIGHT*0.1+160)
                        {
                            if(checkresume)resume=true;else mouse=true;
                            help=false;
                            checkclick=false;
                            //if (!mouse)resume=true;
                        }
                        // button1 click
                        if (mx>=0&&mx<=50&&my>=5&&my<=50)
                        {
                            resume =true;
                            mouse=false;
                            help=false;
                            run=false;
                            checkresume=true;
                            checkclick=false;
                        }

                        // button1 click
                        if (mx>=SCREEN_WIDTH*0.35&&mx<=SCREEN_WIDTH*0.35+64&&my>=SCREEN_HEIGHT*0.75&&my<=SCREEN_HEIGHT*0.75+63)
                        {
                            reset=true;
                        }

                        // button1 click
                        if (mx>=SCREEN_WIDTH*0.6&&mx<=SCREEN_WIDTH*0.6+64&&my>=SCREEN_HEIGHT*0.75&&my<=SCREEN_HEIGHT*0.75+63)
                        {
                         checkquit=true;
                        }

                    }


}

