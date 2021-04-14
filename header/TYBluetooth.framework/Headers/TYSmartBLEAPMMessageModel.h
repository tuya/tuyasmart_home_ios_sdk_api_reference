//
//  TYSmartBLEModel.h
//  TuyaSmartUtil-iOS-TuyaSmartUtil
//
//  Created by 温明妍 on 2019/9/23.
//

#import <Foundation/Foundation.h>
#import "TYSmartBLEAPMEnum.h"

@interface TYSmartBLEAPMMessageModel : NSObject <NSCopying>

@property (nonatomic, strong) NSString *devId;
@property (nonatomic, assign) TYSmartBLEAPMType type;
@property (nonatomic, strong) NSDictionary *dps;
@property (nonatomic, assign) NSTimeInterval time; /**< The time when data is reported.  */
@property (nonatomic, strong) NSString *des; /**< The description.  */
@property (nonatomic, strong) NSDictionary *extInfo; /**< Reserved.  */


- (NSDictionary *)attributes;

@end
