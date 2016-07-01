import tensorflow as tf

v = tf.Variable(0, name='my_variable')
sess = tf.Session()
tf.train.write_graph(sess.graph_def, '', 'blub.pb')
