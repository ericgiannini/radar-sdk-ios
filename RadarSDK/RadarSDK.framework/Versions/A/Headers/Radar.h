//
//  Radar.h
//  RadarSDK
//
//  Copyright © 2016 Radar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "RadarUser.h"
#import "RadarGeofence.h"
#import "RadarEvent.h"

@protocol RadarDelegate;

/**
 * The status types for a request.
 */
typedef NS_ENUM(NSInteger, RadarStatus) {
    RadarStatusSuccess,
    RadarStatusErrorPublishableKey,
    RadarStatusErrorUserId,
    RadarStatusErrorPermissions,
    RadarStatusErrorLocation,
    RadarStatusErrorNetwork,
    RadarStatusErrorUnauthorized,
    RadarStatusErrorServer,
    RadarStatusErrorUnknown
};

@interface Radar : NSObject

/**
 * A block type, called when a location request completes. Receives the request status, the user's location, the events generated, if any, and the user.
 */
typedef void(^ _Nullable RadarCompletionHandler)(RadarStatus status, CLLocation * _Nullable location, NSArray<RadarEvent *> * _Nullable events, RadarUser * _Nullable user);

/**
 @abstract Initializes the Radar SDK.
 @warning You must call this method in application:didFinishLaunchingWithOptions: and pass your publishable API key.
 @param publishableKey Your publishable API key.
 **/
+ (void)initializeWithPublishableKey:(NSString * _Nonnull)publishableKey NS_SWIFT_NAME(initialize(publishableKey:));

/**
 @abstract Identifies the user.
 @warning You must call this method once before calling trackOnce: or startTracking.
 @param userId A stable unique ID for the user.
 **/
+ (void)setUserId:(NSString * _Nonnull)userId;

/**
 @abstract Sets an optional description for the user, displayed in the dashboard.
 @param description A description for the user. If nil, the previous description will be cleared.
 **/
+ (void)setDescription:(NSString * _Nullable)description;

/**
 @abstract Sets an optional delegate for client-side event delivery.
 @param delegate A delegate for client-side event delivery. If nil, the previous delegate will be cleared.
 **/
+ (void)setDelegate:(id<RadarDelegate> _Nonnull)delegate;

/**
 @abstract Returns the app's location authorization status. A convenience method that calls authorizationStatus on CLLocationManager.
 @return A value indicating the app's location authorization status.
 **/
+ (CLAuthorizationStatus)authorizationStatus;

/**
 @abstract Requests permission to track the user's location in the foreground. A convenience method that calls requestWhenInUseAuthorization on the Radar SDK's instance of CLLocationManager.
 **/
+ (void)requestWhenInUseAuthorization;

/**
 @abstract Requests permission to track the user's location in the background. A convenience method that calls requestAlwaysAuthorization on the Radar SDK's instance of CLLocationManager.
 **/
+ (void)requestAlwaysAuthorization;

/**
 @abstract Tracks the user's location once in the foreground.
 @param completionHandler An optional completion handler.
 @warning Before calling this method, you must have called setUserId: once to identify the user, and the user's location authorization status must be kCLAuthorizationStatusAuthorizedWhenInUse or kCLAuthorizationStatusAuthorizedAlways.
 **/
+ (void)trackOnceWithCompletionHandler:(RadarCompletionHandler _Nullable)completionHandler NS_SWIFT_NAME(trackOnce(completionHandler:));

/**
 @abstract Starts tracking the user's location in the background.
 @warning Before calling this method, you must have called setUserId: once to identify the user, and the user's location authorization status must be kCLAuthorizationStatusAuthorizedAlways.
 **/
+ (void)startTracking;

/**
 @abstract Stops tracking the user's location in the background.
 **/
+ (void)stopTracking;

/**
 @abstract Returns a boolean indicating whether the user's location is being tracked in the background.
 @return A boolean indicating whether the user's location is being tracked in the background.
 **/
+ (BOOL)isTracking;

/**
 @abstract Manually updates the user's location.
 @param location A location for the user. Must have a valid latitude, longitude, and accuracy.
 @param completionHandler An optional completion handler.
 @warning Before calling this method, you must have called setUserId: once to identify the user.
 **/
+ (void)updateLocation:(CLLocation * _Nonnull)location withCompletionHandler:(RadarCompletionHandler _Nullable)completionHandler NS_SWIFT_NAME(updateLocation(_:completionHandler:));

/**
 @abstract Returns a boolean indicating whether the user's wi-fi is enabled. Location accuracy and reliability are greatly improved when wi-fi is enabled.
 @return A boolean indicating whether the user's wi-fi is enabled.
 **/
+ (BOOL)isWifiEnabled;

@end
