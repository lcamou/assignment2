df <- data.frame(a=sample(0:9,size = 50,replace = TRUE),
                 b=sample(0:9,size = 50,replace = TRUE),
                 c=sample(0:9,size = 50,replace = TRUE),
                 e=sample(0:9,size = 50,replace = TRUE),
                 f=sample(0:9,size = 50,replace = TRUE),
                 g=sample(0:9,size = 50,replace = TRUE),
                 h=sample(0:9,size = 50,replace = TRUE),
                 i=sample(0:9,size = 50,replace = TRUE))

write.table(df,header=TRUE,sep = ',')

sentences <- sample(1:60, size=25,replace = TRUE)
sentencesMed <- sample(61:96, size = 10, replace = TRUE)
sentencesLong <- sample(97:192, size = 10, replace = TRUE)
sentencesVLong <- sample(193:288, size = 5, replace = TRUE)

sentences <- c(sentences,
               sentencesMed,
               sentencesLong,
               sentencesVLong)

sen <- data.frame(sentence=sentences)
sen$timeServed <- apply(sen,MARGIN = 1,function(x){sample(1:x,size=1, replace = FALSE)})
