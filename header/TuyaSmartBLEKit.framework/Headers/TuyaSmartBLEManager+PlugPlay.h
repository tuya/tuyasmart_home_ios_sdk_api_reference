//
//  TuyaSmartBLEManager+PlugPlay.h
//  TuyaSmartBLEKit
//
//  Created by 吴戈 on 2020/11/9.
//

#import "TuyaSmartBLEManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEManager (PlugPlay)


/// Activate dual-mode device bluetooth mode.
///
/// @param advModel    Device advertisement model.
/// @param homeId      The Id for the current home.
/// @param token       The token.
/// @param success     When activator successfully, this param will be called with DeviceModel.
/// @param failure     This block will be called if some error occurred.
- (void)activatorDualDeviceWithBleChannel:(TYBLEAdvModel *)advModel
                                   homeId:(long long)homeId
                                    token:(NSString *)token
                                  success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                                  failure:(TYFailureError)failure;

/// Dual-mode device which bluetooth channel is actived，to active Wi-Fi channel.
///
/// @param devId       The device Id for the device.
/// @param ssid        The name of the router.
/// @param password    The password Id for the device.
/// @param timeout     Timeout time.
/// @param success     When active successfully, this param will be called with DeviceModel.
/// @param failure     This block will be called if some error occurred.
- (void)activeDualDeviceWifiChannel:(NSString *)devId
                               ssid:(NSString *)ssid
                           password:(NSString *)password
                            timeout:(NSTimeInterval)timeout
                            success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                            failure:(TYFailureError)failure;



@end

NS_ASSUME_NONNULL_END
