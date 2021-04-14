//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)


#import <Foundation/Foundation.h>
#import "TuyaSmartBLEDeviceProtocol.h"
#import <TuyaSmartDeviceCoreKit/TuyaSmartDevice.h>
#import "TuyaSmartBLEManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBeaconManager : NSObject

@property (nonatomic, assign, readonly) BOOL isPoweredOn;

@property (nonatomic, weak) id<TuyaSmartBLEManagerDelegate> delegate;


/// The single instance.
+ (instancetype)sharedInstance;

/// Activates the beacon device.
/// @param advModel The advertisingData model for the beacon device.
/// @param homeId The ID for the current home.
/// @param success When the activation is successful, this block is called with DeviceModel.
/// @param failure If an error occurs, this block is called.
- (void)activeBeacon:(TYBLEAdvModel *)advModel
              homeId:(long long)homeId
             success:(nonnull void (^)(TuyaSmartDeviceModel * _Nonnull))success
             failure:(nonnull TYFailureError)failure ;

/// Publishes the transmitted data.
/// @param deviceId The device ID for the device.
/// @param dps The DP dictionary.
/// @param success After the DPs are sent, this block is called.
/// @param failure  If an error occurs, this block is called.
- (void)publishDpsWithDevicId:(NSString *)deviceId
                          dps:(nonnull NSDictionary *)dps
                      success:(nonnull TYSuccessHandler)success
                      failure:(nonnull TYFailureError)failure;


/// Checks and sets the online status of a device.
/// @param deviceModel The device model.
- (void)checkDeviceOnlineStateWithDevice:(TuyaSmartDeviceModel *)deviceModel;

/// Checks and sets the online status of all beacon devices.
/// @param deviceModelList The device model list.
- (void)checkAllBeaconDeviceOnlineState:(NSArray<TuyaSmartDeviceModel *> *)deviceModelList;

/// Connects to the device and sets the online status of the device.
/// @param deviceId The device ID.
- (void)connectBeaconWithDeviceId:(NSString *)deviceId ;


/// Resets the device and enables the pairing status for the device.
/// @param devId The device ID.
/// @param success After the device is reset, this block is called.
/// @param failure If an error occurs, this block is called.
- (void)resetWithDevId:(NSString *)devId
               success:(TYSuccessHandler)success
               failure:(TYFailureHandler)failure;

///  The online status of the beacon device.
/// @param uuid The UUID of the beacon device.
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;

/// The end of the pairing process.
- (void)stopActive;


@end

NS_ASSUME_NONNULL_END
