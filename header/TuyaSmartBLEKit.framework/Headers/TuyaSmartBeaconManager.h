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


/// Single instance.
+ (instancetype)sharedInstance;

/// Activator beacon device.
/// @param advModel The advertisingData model for the beacon device.
/// @param homeId The Id for the current home.
/// @param success When activator successfully, this block will be called with DeviceModel.
/// @param failure This block will be called if some error occurred.
- (void)activeBeacon:(TYBLEAdvModel *)advModel
              homeId:(long long)homeId
             success:(nonnull void (^)(TuyaSmartDeviceModel * _Nonnull))success
             failure:(nonnull TYFailureError)failure ;

/// Publish the transmitted data.
/// @param deviceId The device Id for the device.
/// @param dps The dp dictionary.
/// @param success When publish dps successfully, this block will be called.
/// @param failure  This block will be called if some error occurred.
- (void)publishDpsWithDevicId:(NSString *)deviceId
                          dps:(nonnull NSDictionary *)dps
                      success:(nonnull TYSuccessHandler)success
                      failure:(nonnull TYFailureError)failure;


/// Check and set device  online status
/// @param deviceModel The device model.
- (void)checkDeviceOnlineStateWithDevice:(TuyaSmartDeviceModel *)deviceModel;

/// Check and set  all Offline device  online status
/// @param deviceModelList The device model list .
- (void)checkAllBeaconDeviceOnlineState:(NSArray<TuyaSmartDeviceModel *> *)deviceModelList;

/// connect device,and set device  online status
/// @param deviceId The device Id for the device.
- (void)connectBeaconWithDeviceId:(NSString *)deviceId ;


/// Reset the device and put the device into the network configuration state
/// @param devId The device Id for the device.
/// @param success When rest successfully, this block will be called.
/// @param failure This block will be called if some error occurred.
- (void)resetWithDevId:(NSString *)devId
               success:(TYSuccessHandler)success
               failure:(TYFailureHandler)failure;

///  Beacon device online state
/// @param uuid beacon device uuid
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;

/// The end of the distribution network
- (void)stopActive;


@end

NS_ASSUME_NONNULL_END
