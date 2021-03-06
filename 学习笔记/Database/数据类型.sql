-- 字符型
-- char 
-- 使用:char(5)  定义能存储5个字符，如果存储不到5个字符后面则用空格补齐
-- varchar
-- 使用:varchar(5) 定义能存储5个字符，它的长度是可变的，不会用空格补齐
-- text
-- 使用:主要用语存储大型字符串
-- nchar
-- nvarchar
-- ntext
-- 使用:性能同上，他们主要用语存储Unicode字符，一个字符用两个字节存储
--
-- 整形
-- int      4字节
-- smallint 2字节
-- tinyint  1字节
-- bigint   8字节
-- bit      只有三个值，1,0,NULL
--
-- 浮点型
-- numeric
-- decimal
-- 使用: numeric(5,2)  表示它接受5个数字，但是只保留2位小数
--
-- money类型
-- money        8字节
-- smallmoney   4字节
--
-- 日期和时间类型
-- date					用于存放日期 
-- time					用于存放时间
-- datetime2			用语存放日期和时间
-- datetimeoffset		用于存放日期、时间和时区
--
-- 二进制类型 
-- binary      使用时需指定长度，默认长度是1
-- varbinary   使用时需指定长度，默认长度是1
-- image	   不用指定长度，通常用来存放图片或文件的信息
--
--

