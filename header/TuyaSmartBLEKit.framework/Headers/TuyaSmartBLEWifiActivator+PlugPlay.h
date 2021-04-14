//
//  TuyaSmartBLEWifiActivator+PlugPlay.h
//  TuyaSmartBLEKit
//
//  Created by 吴戈 on 2020/11/9.
//

#import <TuyaSmartBLEKit/TuyaSmartBLEKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEWifiActivator (PlugPlay)

/// Activates the Zigbee sub-device through the Bluetooth LE channel.
/// The result is returned by TuyaSmartBLEWifiActivatorDelegate.
///
/// @param advModel     The device advertisement model.
/// @param homeId       The ID of the current home.
/// @param device       The gateway device.
/// @param timeout      The timeout value.
- (void)activatorZigbeeSubDeviceWithBleChannel:(TYBLEAdvModel *)advModel
                                        homeId:(long long)homeId
                                 gatewayDevice:(TuyaSmartDevice *)device
                                       timeout:(NSTimeInterval)timeout;

/// Enables the Zigbee sub-device to switch to Zigbee pairing.
///
/// @param advModel     Device advertisement model.
/// @param homeId       The ID of the current home.
/// @param success      When the request is successful, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)switchZigbeeSubDeviceToZigbeeActivator:(TYBLEAdvModel *)advModel
                                        homeId:(long long)homeId
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
