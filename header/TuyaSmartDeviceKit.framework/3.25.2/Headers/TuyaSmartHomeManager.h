//
// TuyaSmartHomeManager.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

#import "TuyaSmartHomeModel.h"

@class TuyaSmartHomeManager;


@protocol TuyaSmartHomeManagerDelegate <NSObject>

@optional

/// The delegate when a new home is added.
///
/// @param manager  instance
/// @param home     homeModel
- (void)homeManager:(TuyaSmartHomeManager *)manager didAddHome:(TuyaSmartHomeModel *)home;

/// The delegate when an existing home is removed.
///
/// @param manager  instance
/// @param homeId   homeId
- (void)homeManager:(TuyaSmartHomeManager *)manager didRemoveHome:(long long)homeId;

/// MQTT service connection success callback.
- (void)serviceConnectedSuccess;


@end

@interface TuyaSmartHomeManager : NSObject

@property (nonatomic, weak) id <TuyaSmartHomeManagerDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartHomeModel *> *homes;


/// Get homes list. If you want to get home details, need to initialize a home, call getHomeDetailWithSuccess: failure:
///
/// @param success Called when the task finishes successfully. A list of TuyaSmartHomeModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeListWithSuccess:(void(^)(NSArray <TuyaSmartHomeModel *> *homes))success
                       failure:(TYFailureError)failure;


/// Adds a new home
///
/// @param homeName    Home name
/// @param geoName     City name
/// @param rooms       Rooms list
/// @param latitude    Latitude
/// @param longitude   Longitude
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addHomeWithName:(NSString *)homeName
                geoName:(NSString *)geoName
                  rooms:(NSArray <NSString *>*)rooms
               latitude:(double)latitude
              longitude:(double)longitude
                success:(TYSuccessLongLong)success
                failure:(TYFailureError)failure;


/// Home sort
///
/// @param homeList    Homes list
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)sortHomeList:(NSArray <TuyaSmartHomeModel *> *)homeList
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;

#pragma mark - deprecated

/// Accept or reject to shared home
///
/// @param homeId       Home Id
/// @param isAccept     Whether to accept the invitation
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::joinFamilyWithAccept:success:failure: instead.
- (void)joinFamilyWithHomeId:(long long)homeId
                      action:(BOOL)isAccept
                     success:(TYSuccessBOOL)success
                     failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome - (void)joinFamilyWithAccept:success:failure:] instead");

@end
