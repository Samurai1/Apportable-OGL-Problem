
#import <Foundation/Foundation.h>
#import "AbstractScene.h"
#import <AVFoundation/AVFoundation.h>
#import "Image.h"

@interface TitleScene : AbstractScene {
	
	Image *TitleIMG;
	BOOL Quit; 
	float Scale;
    float Alpha;
	int Timer;
    int Timer2;
    int RunningTime;
    int Shake;
}



@end
