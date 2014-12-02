#import "SingletonGameState.h"


@implementation SingletonGameState

@synthesize currentlyBoundTexture;


//@synthesize Text;

+ (SingletonGameState*)sharedGameStateInstance {
	
	static SingletonGameState *sharedGameStateInstance;
	
	@synchronized(self) {
		if(!sharedGameStateInstance) {
			sharedGameStateInstance = [[SingletonGameState allocWithZone:NULL] init];
		}
		
	}
	
	return sharedGameStateInstance;
}


- (void) dealloc {
	[super dealloc];
}

@end
