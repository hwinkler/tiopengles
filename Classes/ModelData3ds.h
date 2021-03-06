//
//  ModelData3ds.h
//  tiopengles
//
//  Created by KATAOKA,Atsushi on 11/03/21.
//  Copyright 2011 Langrise Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ModelDataProtocol.h"


@interface ModelData3ds : NSObject <ModelDataProtocol> {
    NSData *dataSource;
    
    NSMutableArray *materials;
    MODEL_CHUNK *model_chunk;
}
- (id)initWithData:(NSData *)data;
@end
