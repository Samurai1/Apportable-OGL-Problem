#import <Foundation/Foundation.h>
#import "SingletonGameState.h"
#import "OperationDraculaAppDelegate.h"



@interface AbstractScene : NSObject {

	SingletonGameState *Manager;
}




-(id) initScene;
-(void) update:(float)delta;
-(void) updateScene:(float)delta;
-(void) render;
-(void) InitData;
-(void) ProcessTouchMovedInLocationX:(CGPoint)TouchLocation;
-(void) ProcessTouchBeganInLocationX:(CGPoint)TouchLocation;
-(void) ProcessTouchEnded;

@end
