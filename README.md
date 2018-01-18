# env
A simple PHP server environment judgment extension
一个简单的PHP判断当前服务器环境的扩展

# php.ini中配置
```ini
[env]
# env.name 默认值为product, 支持product(线上)、gray(灰度)、dev(开发)、local(本地),也支持自定义值
env.name=product
```

# 常量与方法

```php

Class Env{
    /**
     * 当前php.ini中配置的env.name的值
     */
    const ENVIRON = 'product';

    /**
     * isProduct
     * @description 判断是否为线上
     * @version 1.0.0
     * @return bool
     */
    public static function isProduct(){}

    /**
     * isGray
     * @description 判断是否为灰度
     * @version 1.0.0
     * @return bool
     */
    public static function isGray(){}

    /**
     * isDev
     * @description 判断是否为开发
     * @version 1.0.0
     * @return bool
     */
    public static function isDev(){}

    /**
     * isLocal
     * @description 判断是否为本地
     * @version 1.0.0
     * @return bool
     */
    public static function isLocal(){}
}
```
