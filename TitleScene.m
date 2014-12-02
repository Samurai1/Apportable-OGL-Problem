#import "TitleScene.h"


@implementation TitleScene

-(void) InitData{
	TitleIMG=[[Image allocWithZone:NULL] initWithImage:[UIImage imageNamedNoCache:@"Title.png"] controlfile: @"NoControl"  ForceRGB565:NO];
	Scale=1;
	Alpha=1;
}
-(void)render{
    
    Timer++;
    if (Timer>15){
        Timer=0;
        if (Shake==2)
            Shake=0;
        else
            Shake=2;
    }
    
	[TitleIMG renderAtPoint:CGPointMake(160+Shake,240) centerOfImage:YES];
    
    Timer2++;
    if (Timer2==60){
        Timer2=0;
        RunningTime++;
        printf ("Running Time: %d Seconds\n",RunningTime);
        
    }
}

-(void) updateScene:(float)delta{

	if (Quit){
		[TitleIMG setAlpha:Alpha];
		[TitleIMG setScaleX:Scale];
		[TitleIMG setScaleY:Scale];	
		
		Alpha=Alpha-0.010;
		Scale=Scale*1.050;

		if (Alpha<=0){
			Alpha=1;
            Scale=1;
            [TitleIMG setAlpha:1];
            [TitleIMG setScaleX:1];
            [TitleIMG setScaleY:1];
            Quit=NO;
		}
	}
	
	
	
}
-(void) ProcessTouchEnded{
		Quit=YES;

}


@end
