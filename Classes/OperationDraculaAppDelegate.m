

#import "OperationDraculaAppDelegate.h"
#import "EAGLView.h"


@implementation OperationDraculaAppDelegate


- (void)applicationDidFinishLaunching:(UIApplication *)application {


//#ifdef ANDROID
//    [UIScreen mainScreen].currentMode =
//    [UIScreenMode emulatedMode:UIScreenIPhone3GEmulationMode];
//#endif
    
	
	Manager = [SingletonGameState sharedGameStateInstance];
	[[UIApplication sharedApplication] setStatusBarHidden:YES animated:YES];
	[glView startAnimation];
}


- (void)applicationDidEnterBackground:(UIApplication *)application
{
	[glView stopAnimation];
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
	[glView startAnimation];
}
- (void)applicationWillTerminate:(UIApplication *)application{

	[glView DeallocScenes];

}


- (void)dealloc {

	[window release];
	[glView release];
	[super dealloc];
}

@end