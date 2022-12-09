//
//  AlwaysOnScreenView.h
//  AlwaysOnScreenView
//
//  Created by mac on 13/3/20.
//  Copyright © 2020 AdCel LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#define ADCEL_BANNER_VIEW_WILL_BE_REMOVED_NOTIFICATION @"ADCEL_BANNER_VIEW_WILL_BE_REMOVED_NOTIFICATION"

@interface AdCelBaseView : UIView
-(void)addAlwaysOnScreenSubviewToTop:(UIView*)v;
-(void)addAlwaysOnScreenSubviewToBottom:(UIView*)v;
-(void)setupPosition:(NSString*)position insets:(UIEdgeInsets)insets size:(CGSize)size;
@end
