//
//  AdstirRewardVideo.h
//  AdstirAds
//
//  Copyright (c) 2015 UNITED, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    AdstirVideoRewardErrorUnknown,
    AdstirVideoRewardErrorNoFill,
    AdstirVideoRewardErrorFailedToPlayback,
    AdstirVideoRewardErrorInvalidSpot,
    AdstirVideoRewardErrorDidNotInitialize,
    AdstirVideoRewardErrorMediationAdapterNotFound,
} AdstirVideoRewardError;

@class AdstirVideoReward;

@protocol AdstirVideoRewardDelegate <NSObject>

@optional
/**
 動画の再生準備が完了した際に呼び出されます
 */
- (void)adstirVideoRewardDidLoad:(AdstirVideoReward * __nonnull)videoReward;
/**
 動画の再生準備に失敗した際に呼び出されます
 */
- (void)adstirVideoReward:(AdstirVideoReward * __nonnull)videoReward didFailToLoadWithError:(NSError * __nonnull)error;
/**
 動画の再生が開始された際に呼び出されます
 */
- (void)adstirVideoRewardDidStart:(AdstirVideoReward * __nonnull)videoReward;
/**
 動画の再生準備に失敗した際に呼び出されます
 */
- (void)adstirVideoReward:(AdstirVideoReward * __nonnull)videoReward didFailToPlaybackWithError:(NSError * __nonnull)error;
/**
 動画の再生が完了し、リワードが付与された際に呼び出されます
 */
- (void)adstirVideoRewardDidFinishPlayback:(AdstirVideoReward * __nonnull)videoReward;
/**
 動画の再生が完了し、リワードが付与された際に呼び出されます
 */
- (void)adstirVideoRewardDidComplete:(AdstirVideoReward * __nonnull)videoReward;
/**
 動画の再生が完了し、動画再生画面が閉じられたときに呼び出されます
 */
- (void)adstirVideoRewardDidClose:(AdstirVideoReward * __nonnull)videoReward;
/**
 動画の再生がキャンセルされた際に呼び出されます
 ただし、このイベントには全てのアドネットワークが対応しているわけではありません
 */
- (void)adstirVideoRewardDidCancel:(AdstirVideoReward * __nonnull)videoReward;

@end


@interface AdstirVideoReward : NSObject

@property (nonatomic, copy, nonnull) NSString *media;
@property (nonatomic, assign) NSUInteger spot;

@property (nonatomic, assign, readonly) BOOL isPlaying;

@property (nonatomic, weak) __nullable id<AdstirVideoRewardDelegate> delegate;

@property (nonatomic, copy, readonly, nullable) NSString *rewardCurrency;
@property (nonatomic, copy, readonly, nullable) NSString *rewardAmount;

+ (void)setMediaUserID:(NSString * __nonnull)mediaUserID;
+ (NSString * __nullable)mediaUserID;

+ (void)setTestModeEnabled:(BOOL)enabled;
+ (BOOL)testModeEnabled;

+ (void)prepareWithMedia:(NSString * __nonnull)media spots:(NSArray * __nonnull)spots;

- (nullable instancetype)initWithMedia:(NSString * __nonnull)media spot:(NSUInteger)spot;

- (void)load;

- (void)show;

- (BOOL)canShow;

@end
