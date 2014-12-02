
#import "AbstractScene.h"


@implementation AbstractScene


-(id) initScene{
	
	
	self = [super init];
	if (self != nil) {
		
		Manager = [SingletonGameState sharedGameStateInstance];
		[self InitData];
		
	}
	return self;
	
	
}

-(id)init{ 

self = [super init];
if (self != nil) {

	[self InitData];
	
}
return self;

}

-(void) InitData{
	
}



-(void) update:(float)delta{
	
	[self updateScene:delta];
}

-(void) updateScene:(float)delta{
	
}


-(void) render{
	
	
}


-(void) ProcessTouchBeganInLocationX:(CGPoint)TouchLocation{
	
	
}
-(void) ProcessTouchMovedInLocationX:(CGPoint)TouchLocation{
		
}

-(void) ProcessTouchEnded{
}	

@end
