## Seq2Seq Tasks
### ML2023-HW5-Translation
model here :point_right: : [link](https://github.com/stephanie0324/ML_practrice/blob/master/Seq2Seq/ML2023-HW5-Translation.ipynb)
1. In strong basleine (can't log in to JudgeBoi)
2. TODOs
   * Train a simple RNN seq2seq to acheive translation -> add layers and more epochs
   * Switch to transformer model to boost performance -> change to transformer encoder and decoder
   * Apply Back-translation to furthur boost performance (pass)
### ML2023-HW7-Question_Answering
model here :point_right: : [link](https://github.com/stephanie0324/ML_practrice/blob/master/Seq2Seq/ML2023_HW7_Question_Answering.ipynb)
1. In strong basleine :white_check_mark:
2. TODOs
   * Fine tune a pretrained chinese BERT model
   * Change hyperparameters (e.g. doc_stride) -> make it overlap
      * doc_stride = distance between the start position of two consecutive windows -> make the distance smaller
   * Apply linear learning rate decay
      * method 1 : decrement optimizer.param_groups[0]["lr"] by learning_rate / total training step
         ```ruby
         learning_rate = 1e-4
         optimizer = AdamW(model.param, lr=learing_rate)
         total_step = 10000
         for i in range(total_step):
             optimizer.param_groups[0]["lr"] = learning_rate / total_step
         ```
      * :point_right: method 2 : adjust learing rate by scheduler (linearLR)
   * Try other pretrained models : roberta-qa-chinese
   * Improve preprocessing : starting index move forward
   * Improve postprocessing : remove pred_end < pred_start 
