//
//  AdstirMraidView.h
//  AdstirAds
//
//  Copyright (c) 2013- UNITED, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "AdstirAdSize.h"

// Don't refresh. / ローテーション無効
#define ADSTIRWEBVIEW_NO_INTERVAL 0
// Minimum refresh interval. / 最小のローテーション感覚
#define ADSTIRWEBVIEW_MIN_INTERVAL 30
// Default refresh interval. / デフォルトのローテーション時間
#define ADSTIRWEBVIEW_DEFAULT_INTERVAL 60

@class AdstirMraidView;

@protocol AdstirMraidViewDelegate <NSObject>
@optional
/**
 Perfoemed before expanded screen will present.
 
 エキスパンド広告が表示される前に呼び出されます。
 */
- (void)adstirMraidViewWillPresentScreen:(AdstirMraidView * __nonnull)mraidView;
/**
 Perfoemed after expanded screen did present.
 
 エキスパンド広告が表示された後に呼び出されます。
 */
- (void)adstirMraidViewDidPresentScreen:(AdstirMraidView * __nonnull)mraidView;
/**
 Performed before expanded screen will dismiss.
 
 エキスパンド広告が閉じられる前に呼び出されます。
 */
- (void)adstirMraidViewWillDismissScreen:(AdstirMraidView * __nonnull)mraidView;
/**
 Performed before leave application.
 
 広告がクリックされ、標準ブラウザなどを開く前に呼び出されます。
 */
- (void)adstirMraidViewWillLeaveApplication:(AdstirMraidView * __nonnull)mraidView;
@end

@interface AdstirMraidView : UIView

/**
 Set refresh time in seconds.
 
 ローテーション時間(秒)を設定します。
 */
@property (assign) NSUInteger  intervalTime;

/**
 Set delegate.
 
 デリゲートを設定します。
 */
@property (weak) __nullable id<AdstirMraidViewDelegate> delegate;

/**
 Set media ID.
 
 メディアIDを設定します。
 */
@property (nonatomic, copy, nonnull) NSString*  media;
/**
 Set spot number.
 
 枠Noを設定します。
 */
@property (nonatomic, assign) NSUInteger spot;

/**
 Initialize with origin at top left of parent view.
 
 親ビューの左上を起点として初期化します。
 */
- (nullable instancetype)initWithAdSize:(AdstirAdSize)size media:(NSString * __nonnull)media spot:(NSUInteger)spot;
/**
 Initialize with custome origin to parent view.
 
 親ビューに対する位置を指定して初期化します。
 */
- (nullable instancetype)initWithAdSize:(AdstirAdSize)size origin:(CGPoint)origin media:(NSString * __nonnull)media spot:(NSUInteger)spot;

/**
 位置情報を広告配信に利用する場合に使用します。
 エンドユーザーへの許諾無しに、位置情報を利用することはできません。
 */
- (void)setLocationWithLatitude:(CGFloat)latitude
                      longitude:(CGFloat)longitude
                       accuracy:(CGFloat)accuracyInMeters;

/**
 Start loading.
 
 読み込みを開始します。
 */
- (void)start;
/**
 Stop loading.
 
 読み込みを停止します。
 */
- (void)stop;
@end
