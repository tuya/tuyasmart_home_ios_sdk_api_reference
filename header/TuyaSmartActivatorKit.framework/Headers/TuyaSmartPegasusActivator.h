//
// TuyaSmartPegasusActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartPegasusActivator;
@protocol TuyaSmartPegasusActivatorDelegate <NSObject>

/// Devices found by Pegasus.
/// @param activator Activator instance.
/// @param serverDeviceModel The device is found, but there is no device ID at this time.
/// @param deviceModel The device is found, but there is no device ID at this time.
/// @param error Error message.
- (void)pegasusActivator:(TuyaSmartPegasusActivator *)activator serverDevice:(TuyaSmartDeviceModel *)serverDeviceModel didFoundDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError * __nullable)error;

/// Devices that have been configured for the network by Pegasus.
/// @param activator Activator instance.
/// @param deviceModel The found device.
/// @param error Error message.
- (void)pegasusActivator:(TuyaSmartPegasusActivator *)activator didReceiveDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError * __nullable)error;

@end

/// @brief TuyaSmartPegasusActivator is used for pegasus configuration.
///
/// This class provides pegasus configuration capabilities.
///
@interface TuyaSmartPegasusActivator : NSObject

@property (nonatomic, weak) id<TuyaSmartPegasusActivatorDelegate> delegate;

/// Devices supporting Pegasus.
/// @param homeID The home ID.
/// @return A list of devices that support Pegasus.
+ (NSArray <TuyaSmartDeviceModel *> *)pegasusDeviceListWithHomeID:(long long)homeID;

/// Start Pegasus Activator discover pending device.
///
/// The 'devIDs' should be obtained form TuyaSmartPegasusActivator::pegasusDeviceListWithHomeID:
///
/// @param devIDs Device ID list
/// @param serverTimeout Configured devices, search timeout for devices to be configured.
/// @param clientTimeout Pending devices, pending devices is searched for and not added to the family timeout.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIDs:(NSArray<NSString *> *)devIDs
                  serverTimeout:(NSTimeInterval)serverTimeout
                  clientTimeout:(NSTimeInterval)clientTimeout
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;


/// Already distributed devices stop continuing to discover equipment to be configured.
///
/// The 'devIDs' should be obtained form TuyaSmartPegasusActivator::pegasusDeviceListWithHomeID:
///
/// @param devIDs A list of devices that support Pegasus.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)stopDiscoverWithDevIDs:(NSArray<NSString *> *)devIDs
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;


/// Configure of found devices to be configured on the network.
///
/// The 'token' can be obtained form TuyaSmartActivator::getTokenWithHomeId:success:failure:
///
/// @param devIDs A list of devices that support Pegasus.
/// @param UUIDs List of UUIDs of devices to be configured.
/// @param token The configuration token.
/// @param timeout Timeout time, default 100s.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startActivatorWithDevIDs:(NSArray<NSString *> *)devIDs
                           UUIDs:(NSArray<NSString *> *)UUIDs
                           token:(NSString *)token
                         timeout:(NSTimeInterval)timeout
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;


/// Cancel the configuration of devices that being discovered by Pegasus.
/// @param devIDs A list of devices that support Pegasus.
/// @param UUIDs List of UUIDs of devices to be configured.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelActivatorWithDevIDs:(NSArray<NSString *> *)devIDs
                            UUIDs:(NSArray<NSString *> *)UUIDs
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
