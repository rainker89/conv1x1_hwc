void Conv2d_neon_impl_float_hwc::run_1x1_hwc(TensorType *input, TensorType *kernel, TensorType *output)
{
#if __ARM_NEON
	float* buffer_out = output->rawdata();
	float* buffer_in = input->rawdata();
	float* buffer_kernel = kernel->rawdata();

	int channel_out = static_cast<int>(kernel->dim(0));
	int channel_in = static_cast<int>(kernel->dim(3));		//
	int height = static_cast<int>(output->dim(1));			//
	int width = static_cast<int>(output->dim(2));			//
	

	float* ptr_out;

	float32x4_t vc11, vc12, vc13, vc14;
	float32x4_t vc21, vc22, vc23, vc24;
	float32x4_t vc31, vc32, vc33, vc34;
	float32x4_t vc41, vc42, vc43, vc44;



	int pix=0;
	for(; pix + 3 < height * width; pix += 4)
	{
		int oc =0;
		for(; oc + 3 < channel_out; oc += 4)
		{
			
			ptrc = buffer_out + (i-1)*channel_out + oc;
			
			vc11 = vdupq_n_f32( 0 );
			vc12 = vdupq_n_f32( 0 );
			vc13 = vdupq_n_f32( 0 );
			vc14 = vdupq_n_f32( 0 );
		
			vc21 = vdupq_n_f32( 0 );
			vc22 = vdupq_n_f32( 0 );
			vc23 = vdupq_n_f32( 0 );
			vc24 = vdupq_n_f32( 0 );

			vc31 = vdupq_n_f32( 0 );
			vc32 = vdupq_n_f32( 0 );
			vc33 = vdupq_n_f32( 0 );
			vc34 = vdupq_n_f32( 0 );

			vc41 = vdupq_n_f32( 0 );
			vc42 = vdupq_n_f32( 0 );
			vc43 = vdupq_n_f32( 0 );
			vc44 = vdupq_n_f32( 0 );

			ptra1 = buffer_in + height*width*channel_in - 4;
			ptra2 = ptra1 + channel_in;
			ptra3 = ptra2 + channel_in;
			ptra4 = ptra3 + channel_in;

			ptrb1 = buffer_kernel + channel_out*channel_in -4;
			ptrb2 = ptrb1 + channel_in;
			ptrb3 = ptrb2 + channel_in;
			ptrb4 = ptrb3 + channel_in;
			
			int chan = 0;
			for ( int chan = 0; chan+3 < channel_in; k += 4 )
			{	
					
				va1 = vld1q_f32( ptra1 += 4 );
				va2 = vld1q_f32( ptra2 += 4 );
				va3 = vld1q_f32( ptra3 += 4 );
				va4 = vld1q_f32( ptra4 += 4 );

				vb1 = vld1q_f32( ptrb1 +=4 );
				vb2 = vld1q_f32( ptrb2 +=4 );
				vb3 = vld1q_f32( ptrb3 +=4 );
				vb4 = vld1q_f32( ptrb4 +=4 );
				
				
				
				vc11 = vmlaq_f32( vc11, va1, vb1 );
				vc12 = vmlaq_f32( vc12, va1, vb2 );
				vc13 = vmlaq_f32( vc13, va1, vb3 );
				vc14 = vmlaq_f32( vc14, va1, vb4 );
			
				vc21 = vmlaq_f32( vc21, va2, vb1 );
				vc22 = vmlaq_f32( vc22, va2, vb2 );
				vc23 = vmlaq_f32( vc23, va2, vb3 );
				vc24 = vmlaq_f32( vc24, va2, vb4 );

				vc31 = vmlaq_f32( vc31, va3, vb1 );
				vc32 = vmlaq_f32( vc32, va3, vb2 );
				vc33 = vmlaq_f32( vc33, va3, vb3 );
				vc34 = vmlaq_f32( vc34, va3, vb4 );
				
				vc41 = vmlaq_f32( vc41, va4, vb1 );
				vc42 = vmlaq_f32( vc42, va4, vb2 );
				vc43 = vmlaq_f32( vc43, va4, vb3 );
				vc44 = vmlaq_f32( vc44, va4, vb4 );
			}
			
		


			
			temp1 = vpaddq_f32( vc11,vc12 );
			temp2 = vpaddq_f32( vc13,vc14 );
			temp3 = vpaddq_f32( temp1, temp2 );
			vst1q_f32( ptrc+=b, temp3 );
			
			temp1 = vpaddq_f32( vc21,vc22 );
			temp2 = vpaddq_f32( vc23,vc24 );
			temp3 = vpaddq_f32( temp1, temp2 );
			vst1q_f32( ptrc+=b, temp3 );

			temp1 = vpaddq_f32( vc31,vc32 );
			temp2 = vpaddq_f32( vc33,vc34 );
			temp3 = vpaddq_f32( temp1, temp2 );
			vst1q_f32( ptrc+=b, temp3 );

			temp1 = vpaddq_f32( vc41,vc42 );
			temp2 = vpaddq_f32( vc43,vc44 );
			temp3 = vpaddq_f32( temp1, temp2 );
			vst1q_f32( ptrc+=b, temp3 );
			ptr -=4*b;
			for( int i =0; i<4; i++)
			{
				for( int j=0; j<4; j++)
				{
					for( int k=0; k < channel_in - chan; k++)
					{
						*(ptrc + i* chanel_out + j) += *
			while(chan < channel_in)
			{
				*ptrc++ += *(ptra1) * *(ptrb1++);
				*ptrc++ += *(ptra1) * *(ptrb2++);





		}

