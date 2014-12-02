

#import <UIKit/UIKit.h>
#import "SingletonGameState.h"
#import <AVFoundation/AVFoundation.h>

@class EAGLView;



@interface OperationDraculaAppDelegate : NSObject <UIApplicationDelegate> {
 
	
	
	UIWindow *window;
    EAGLView *glView;
	SingletonGameState *Manager;
	
	BOOL Initialized;
	
	
}


@end


