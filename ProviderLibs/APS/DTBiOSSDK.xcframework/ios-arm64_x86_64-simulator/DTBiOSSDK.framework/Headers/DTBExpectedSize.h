//
//  DTBExpectedSize.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DTBExpectedSize <NSObject>

@property(nonatomic)NSNumber * _Nullable targetWidth;
@property(nonatomic)NSNumber * _Nullable targetHeight;

@end

NS_ASSUME_NONNULL_END
